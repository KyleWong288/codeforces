#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

ll n, x, y;

// if x >= y, its just ceil(n / y)
// if x < y, its ceil(n / x)
ll solve() {
    if (x >= y) {
        return (n + y - 1) / y;
    }
    else {
        return (n + x - 1) / x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> x >> y;
        res[i] = solve();
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}