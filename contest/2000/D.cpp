#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

ll solve(vector<ll>& a, string& s) {
    ll res = 0;
    int l = 0, r = N-1;
    vector<ll> ps(N+1);
    for (int i=0; i<N; ++i) {
        ps[i+1] = ps[i] + a[i];
    }
    while (1) {
        while (l < r && s[l] != 'L') ++l;
        while (l < r && s[r] != 'R') --r;
        if (l >= r) break;
        res += (ps[r+1] - ps[l]);
        --r;
        ++l;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<ll> a(N);
        for (auto& x : a) cin >> x;
        string s;
        cin >> s;
        res[i] = solve(a, s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}