#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M, K;

int solve(vector<int>& l, vector<int>& r) {
    int res = 0;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            res += (l[i] + r[j] <= K);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M >> K;
        vector<int> l(N);
        vector<int> r(M);
        for (auto& x : l) {
            cin >> x;
        }
        for (auto& x : r) {
            cin >> x;
        }
        res[i] = solve(l, r);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}