#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// build with all horizontal (1x2), use (1x3) if m is odd
int solve(int n, int m) {
    int res = 0;
    res = n * (m / 2);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int n, m;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> m;
        res[i] = solve(n, m);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}