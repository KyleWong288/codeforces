#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

ll x, y, z, k;

// just think 2d
// generally, you want the shape of S to be as proportional to B as possible... unimportant
// side length triples are brute forcable LOL: i only brute force (x,y) and satisfy z
// usable area: (x - sx + 1) * (y - sy + 1) * (z - sz + 1)
ll solve() {
    ll res = 0;
    vector<int> xs;
    for (int i=1; i<=x; ++i) {
        if (k % i == 0) xs.push_back(i);
    }
    vector<int> ys;
    for (int i=1; i<=y; ++i) {
        if (k % i == 0) ys.push_back(i);
    }
    for (auto& sx : xs) {
        for (auto& sy : ys) {
            if (k % (sx * sy)) continue;
            ll sz = k / (sx * sy);
            if (sz > z) continue;
            res = max(res, (x - sx + 1) * (y - sy + 1) * (z - sz + 1));
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
        cin >> x >> y >> z >> k;
        res[i] = solve();
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}