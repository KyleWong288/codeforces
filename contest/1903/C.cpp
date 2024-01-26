#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <numeric>
using namespace std;
typedef long long ll;

int N;

// decomposed answer looks like 1(suff 1) + 2(suff 2) + 3(suff 3) ...
// if suffix sum is positive, always make a new subarray
ll solution(vector<ll>& a) {
    vector<ll> suff(N+1, 0);
    for (int i=N-1; i>=0; --i) {
        suff[i] = suff[i+1] + a[i];
    }
    ll res = 0;
    ll coeff = 1;
    for (int i=0; i<N; ++i) {
        res += coeff * a[i];
        if (suff[i+1] > 0) {
            ++coeff;
        }
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