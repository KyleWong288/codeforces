#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

ll a,b,l;

ll safePow(ll base, ll exp) {
    ll res = 1;
    for (int i=0; i<exp; ++i) {
        res *= base;
        if (res > 1e9) return 1e9;
    }
    return res;
}

// brute force each exponent pair (x,y)
int solve() {
    set<ll> ks;
    for (ll x=0; x<60; ++x) {
        for (ll y=0; y<60; ++y) {
            ll powA = safePow(a, x);
            ll powB = safePow(b, y);
            if (powA * powB > l) continue;
            if (l % (powA * powB) == 0) {
                ll k = l / (powA * powB);
                ks.insert(k);
            }
        }
    }
    int res = ks.size();
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> a >> b >> l;
        res[i] = solve();
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}