#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

int N, M, K, Q;
const int MOD = 998244353;

// answer is k ^ (# of cross ops that are still visible)
// cross op becomes unvisible if entire row and entire col covered
// entire row covered: exact same row is covered, or all cols are covered after
// entire col covered: exact same col is covered, or all rows are covered after
int solution(vector<vector<int>>& ops) {
    ll cnt = 0;
    set<int> usedRows;
    set<int> usedCols;
    for (int i=Q-1; i>=0; --i) {
        int r = ops[i][0];
        int c = ops[i][1];
        bool covRow = (usedCols.size() == M || usedRows.find(r) != usedRows.end());
        bool covCol = (usedRows.size() == N || usedCols.find(c) != usedCols.end());
        if (!covRow || !covCol) {
            ++cnt;
        }
        usedRows.insert(r);
        usedCols.insert(c);
    }
    ll res = 1;
    while (cnt--) {
        res = res * K % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M >> K >> Q;
        vector<vector<int>> ops(Q, vector<int>(2));
        for (int j=0; j<Q; ++j) {
            cin >> ops[j][0] >> ops[j][1];
        }
        res[i] = solution(ops);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}