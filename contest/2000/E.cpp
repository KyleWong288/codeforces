#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int n, m, k, w;

// need to work on math...
// how many sqaures does cell at (i,j) take part of?
// for i: touched by the range [max(0, i-k+1), min(i+1, n-k+1)]
// sort and match
ll solve(vector<ll>& a) {
    vector<int> coeffs(n*m);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            ll x = min(j+1, m-k+1) - max(0, j-k+1);
            x = max(x, 1LL);
            ll y = min(i+1, n-k+1) - max(0, i-k+1);
            y = max(y, 1LL);
            coeffs[m*i+j] = x * y;
        }
    }
    sort(a.rbegin(), a.rend());
    sort(coeffs.rbegin(), coeffs.rend());
    cout << endl;
    ll res = 0;
    for (int i=0; i<w; ++i) {
        res += a[i] * coeffs[i];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> m >> k >> w;
        vector<ll> a(w);
        for (auto& x : a) cin >> x;
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}