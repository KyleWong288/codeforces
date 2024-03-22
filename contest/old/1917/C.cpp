#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int n, k, d;

// as soon as you cash out, always alternate between add and cash out 
// math: first cashout at day i, we get (d - i) / 2 from remaining
// when to do first cashout? try up to 2*n since our alternating approach gets half points
// we need to mod k, so make 0 indexed, which means d--
ll solve(vector<ll>& a, vector<ll>& b) {
    --d;
    // try cash out without using any add ops
    int good = 0;
    for (int i=0; i<n; ++i) {
        good += (a[i] == i+1);
    }
    ll res = good + d / 2;
    for (int op=0; op<min(2*n+5, d); ++op) {
        good = 0;
        int end = b[op % k];
        for (int i=0; i<n; ++i) {
            if (i < end) {
                a[i]++;
            }
            good += (a[i] == i+1);
        }
        // we add on day op, so cashout on day op+1
        ll newRes = good + (d - (op + 1)) / 2;
        res = max(res, newRes);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> k >> d;
        vector<ll> a(n);
        for (auto& x : a) {
            cin >> x;
        }
        vector<ll> v(k);
        for (auto& x : v) {
            cin >> x;
        }
        res[i] = solve(a, v);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}