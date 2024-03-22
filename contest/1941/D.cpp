#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M, X;

// dp[i][j] = at time step i, player j can have the ball
// then compute his left and right neighbor, they can have the ball at time i+1
void solve(vector<vector<int>>& throws) {
    // dp[i][j] = at time step i, player j can have the ball
    vector<vector<bool>> dp(M+1, vector<bool>(N, 0));
    dp[0][X-1] = 1;
    for (int i=0; i<M; ++i) {
        int dist = throws[i][0];
        int dir = throws[i][1];
        for (int j=0; j<N; ++j) {
            if (!dp[i][j]) continue;
            if (dir == 0) {
                int dest = (j + dist) % N;
                dp[i+1][dest] = 1;
            }
            else if (dir == 1) {
                int dest = (j - dist + N) % N;
                dp[i+1][dest] = 1;
            }
            else {
                int dest1 = (j + dist) % N;
                int dest2 = (j - dist + N) % N;
                dp[i+1][dest1] = 1;
                dp[i+1][dest2] = 1;
            }
        }
    }
    vector<int> res;
    for (int i=0; i<N; ++i) {
        if (dp[M][i]) res.push_back(i);
    }
    cout << res.size() << endl;
    for (auto& r : res) {
        cout << r+1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M >> X;
        vector<vector<int>> throws(M, vector<int>(2, 0));
        for (int i=0; i<M; ++i) {
            char ch;
            cin >> throws[i][0] >> ch;
            if (ch == '0') {
                throws[i][1] = 0;
            }
            else if (ch == '1') {
                throws[i][1] = 1;
            }
            else {
                throws[i][1] = -1;
            }
        }
        solve(throws);
    }
    return 0;
}