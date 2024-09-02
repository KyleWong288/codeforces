#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M;

void solve(vector<int>& a, vector<vector<int>>& ops) {
    vector<int> res(M);
    int curMax = *max_element(a.begin(), a.end());
    for (int i=0; i<M; ++i) {
        int l = ops[i][1], r = ops[i][2];
        if (ops[i][0] == 1) {
            if (l <= curMax && curMax <= r) ++curMax;
        }
        else {
           if (l <= curMax && curMax <= r) --curMax; 
        }
        res[i] = curMax;
    }
    for (auto& x : res) cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    char ch;
    int l, r;
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<int> a(N);
        for (auto& x : a) cin >> x;
        vector<vector<int>> ops(M);
        for (int i=0; i<M; ++i) {
            cin >> ch >> l >> r;
            if (ch == '+') {
                ops[i] = {1, l, r};
            }
            else {
                ops[i] = {-1, l, r};
            }
        }
        solve(a, ops);
    }
    return 0;
}