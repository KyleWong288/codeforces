#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;

int N, K;

// checks if A follows the base format
bool verify(vector<int>& base, vector<int>& a) {
    int j = 1;
    for (int i=0; i<N; ++i) {
        if (base[i] == a[0]) {
            --j;
        }
        else if (base[i] != a[j]) {
            return 0;
        }
        ++j;
    }
    return 1;
}

// just get the order from the first 2, then verify the remaining
// if 1 and 2 are next to each other, their order is ambigious. so just try both orders
int solve(vector<vector<int>>& a) {
    if (K == 1) return 1;
    // get base order:
    vector<int> base(N);
    int use0 = -1, use1 = -1;
    int p0 = 1, p1 = 1, idx = 0;
    while (p0 < N && p1 < N) {
        if (a[0][p0] == a[1][0]) {
            use1 = idx;
            base[idx] = a[1][0];
            --p1;
        }
        else if (a[1][p1] == a[0][0]) {
            use0 = idx;
            base[idx] = a[0][0];
            --p0;
        }
        else if (a[0][p0] == a[1][p1]) {
            base[idx] = a[0][p0];
        }
        else {
            return 0;
        }
        ++idx;
        ++p0;
        ++p1;
    }
    if (use1 == -1) {
        base[N-1] = a[1][0];
        use1 = N-1;
    }
    if (use0 == -1) {
        base[N-1] = a[0][0];
        use0 = N-1;
    }
    // verify remaining:
    bool good1 = 1, good2 = 1;
    for (int i=2; i<K; ++i) {
        if (!verify(base, a[i])) {
            good1 = 0;
        }
    }
    // if 1 and 2 are neighbors, try other order
    if (abs(use0 - use1) == 1) {
        swap(base[use0], base[use1]);
        for (int i=2; i<K; ++i) {
            if (!verify(base, a[i])) {
                good2 = 0;
            }
        }
    }
    else {
        good2 = 0;
    }
    return (good1 || good2);
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
        vector<vector<int>> a(K, vector<int>(N));
        for (auto& row : a) {
            for (auto& x : row) {
                cin >> x;
            }
        }
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << (r ? "YES\n" : "NO\n");
    }
    return 0;
}