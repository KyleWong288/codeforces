#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

ll solve(int x, int y) {
    ll res = 1;
    for (int i=0; i<32; ++i) {
        int bx = (x >> i) & 1;
        int by = (y >> i) & 1;
        if (bx == by) {
            res *= 2;
        }
        else {
            break;
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
        int x, y;
        cin >> x >> y;
        res[i] = solve(x, y);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}