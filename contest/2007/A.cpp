#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// take 2 odds spaced 2 apart, and the 1 even in between
int solve(int l, int r) {
    int res = 0;
    if (l % 2 == 0) ++l;
    while (l+2 <= r) {
        ++res;
        l += 4;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        int l, r;
        cin >> l >> r;
        res[i] = solve(l, r);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}