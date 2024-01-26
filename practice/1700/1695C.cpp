#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N, M;

// track smallest and largest way to get to (i,j), this means we can reach (i,j) with all values with the same parity in [smallest, largest]
// idea: each cell has 2 ways to reach it, so if both cells are same we change by 1 option, but if both cells are different we change by 2 options
int solution(vector<vector<int>>& g) {
    if ((N + M) % 2 == 0) {
        return 0;
    }
    // dp[i][j] = {smallest, largest} way to get to (i,j)
    vector<vector<pair<int,int>>> dp(N, vector<pair<int,int>>(M));
    // base case:
    dp[0][0] = {g[0][0], g[0][0]};
    for (int i=1; i<M; ++i) {
        dp[0][i] = {g[0][i] + dp[0][i-1].first, g[0][i] + dp[0][i-1].second};
    }
    for (int i=1; i<N; ++i) {
        dp[i][0] = {g[i][0] + dp[i-1][0].first, g[i][0] + dp[i-1][0].second};
    }
    // regular dp:
    for (int i=1; i<N; ++i) {
        for (int j=1; j<M; ++j) {
            int small = min(dp[i-1][j].first, dp[i][j-1].first);
            int large = max(dp[i-1][j].second, dp[i][j-1].second);
            dp[i][j] = {g[i][j] + small, g[i][j] + large};
        }
    }
    int small = dp[N-1][M-1].first;
    int large = dp[N-1][M-1].second;
    if (small <= 0 && 0 <= large) {
        return 1;
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<vector<int>> grid(N, vector<int>(M, 0));
        for (int r=0; r<N; ++r) {
            for (int c=0; c<M; ++c) {
                cin >> grid[r][c];
            }
        }
        res[i] = solution(grid);
    }
    for (auto& r : res) {
        if (r) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}