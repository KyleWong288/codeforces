#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// inc subarray of size n generates 2^n-1 inc ssqs (minus one since no empty ssq)
// so we have easy building blocks of about 2^n
// concerns about length?: this is minimal length since to get 2^(n+1), we add only 1 extra element
// if we have a suffix of 1s (2^n-1), then we can do with one block and save length
// all values in previous blocks should be > later blocks to avoid extra inc ssqs
// how to add back -1s?: if we add some value at i=0 > all values except for the last value in each block, we get +1 per block
void solve(ll n) {
    vector<int> bits(64);
    for (int i=0; i<64; ++i) {
        bits[i] = (n >> i) & 1;
    }
    int cnt = 1;
    int sz = 0;
    int val = 10000;
    vector<vector<int>> res(64);
    for (int b=63; b>=0; --b) {
        if (bits[b]) {
            vector<int> v(b);
            for (int i=0; i<b; ++i) {
                v[i] = val + i;
            }
            res[b] = v;
            val -= 100;
            sz += b;
            cnt += (1 << b);
        }
    }
    for (int i=63; i>=0; --i) {

    }
    if (sz > 200 || cnt != n) {
        cout << -1 << endl;
        return;
    }
    cout << sz << endl;
    for (auto& row : res) {
        for (auto& x : row) {
            cout << x << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    ll n;
    while (T--) {
        cin >> n;
        solve(n);
    }
    return 0;
}