#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int n, k, x;

// Bob goal is easy: always set the x largest to negative
// Alice goal needs to brute force: remove some amount of the largest (try all from [0,k])
ll solution(vector<ll>& a) {
    sort(a.rbegin(), a.rend());
    vector<ll> ps(n+1);
    for (int i=0; i<n; ++i) {
        ps[i+1] = ps[i] + a[i];
    }
    ll res = -2e9;
    for (int i=0; i<=k; ++i) {
        int end = min(n, i+x);
        int rem = ps[i] - ps[0];
        int rev = ps[end] - ps[i];
        ll total = ps[n] - rem - 2 * rev;
        res = max(res, total);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> k >> x;
        vector<ll> a(n);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solution(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}