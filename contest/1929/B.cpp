#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// just take from left side or right side
// generally, each new point adds two new diagonals
// corners are special, they may only add one new diagonal, so use non corners first
// adds look like a bunch of 2s, and then two 1s
int solve(int n, int k) {
    int cap = 4 * n - 2;
    int doubles = 2 * n - 2;
    if (k <= cap - 2) {
        return (k+1) / 2;
    }
    if (k == cap - 1) {
        return doubles + 1;
    }
    return doubles + 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int n, k;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> k;
        res[i] = solve(n, k);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}