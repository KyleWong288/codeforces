#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

ll n, a, b;

// sell modified buns while b - k + 1 >= a -> k = b - a + 1
// fast compute: len / 2 * (l + r)
ll solve() {
    // k is the number of modified buns i use
    ll k = b - a + 1;
    k = min(k, min(n, b));
    if (k > 0) {
        // l is ending price of modified buns
        ll l = b - k + 1;
        // r is starting price of modified buns
        ll r = b;
        ll modify = (l + r) * (r - l + 1) / 2;
        return modify + (n - k) * a;
    }
    else {
        return a * n;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> a >> b;
        res[i] = solve();
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}