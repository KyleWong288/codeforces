#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

int n, x, y;

// cond 1: (a + b) % x = 0 -> ((a % x) + (b % x)) % x = 0, so get modular pair
// cond 2: (a - b) % y = 0 -> ((a % y) - (b % y)) % y = 0 -> (a % y) == (b % y), so just get modular equal
// batch by modulo y, then within that batch, count modulo x
ll solve(vector<int>& a) {
    ll res = 0;
    // freq[i][j] = freq of all K such that K % y == i and K % x == j
    map<int, map<int,int>> freq;
    for (auto& val : a) {
        int modY = val % y;
        int modX = val % x;
        int other = (x - modX) % x;
        res += freq[modY][other];
        freq[modY][modX]++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> x >> y;
        vector<int> a(n);
        for (auto& val : a) {
            cin >> val;
        }
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}