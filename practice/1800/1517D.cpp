#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;
typedef long long ll;

int n, m, K;

int id(int r, int c) {
    int res = r * m + c;
    return res;
}

// k works iff k is even
// for the optimal path, whatever path you use to get to the end, use the same path to go back
// use floyd warshall-ish?? however we can repeat edges and add vertices by nearness
// need to solve for all k-1 before moving onto to k, we are adding to the PREFIX
void solution(vector<unordered_map<int,int>>& adj) {
    if (K % 2) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                cout << -1 << " ";
            }
            cout << endl;
        }
        return;
    }
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    // dp[k][i][j] = shortest path starting at (i,j), using k edges
    vector<vector<vector<int>>> dp(K/2+1, vector<vector<int>>(n, vector<int>(m, 1e9)));
    for (int r=0; r<n; ++r) {
        for (int c=0; c<m; ++c) {
            dp[0][r][c] = 0;
        }
    }
    for (int k=1; k<=K/2; ++k) {
        for (int r=0; r<n; ++r) {
            for (int c=0; c<m; ++c) {
                int minW = 1e9;
                for (int mv=0; mv<4; ++mv) {
                    int nr = r + dr[mv];
                    int nc = c + dc[mv];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        int u = id(r, c);
                        int v = id(nr, nc);
                        minW = min(minW, dp[k-1][nr][nc] + adj[u][v]);
                    }
                }
                dp[k][r][c] = minW;
            }
        }
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cout << 2 * dp[K/2][i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> K;
    int w;
    // adj[u][v] = weight of edge from u to v
    vector<unordered_map<int,int>> adj(n*m);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m-1; ++j) {
            cin >> w;
            int u = id(i, j);
            int v = id(i, j+1);
            adj[u].insert({v, w});
            adj[v].insert({u, w});
        }
    }
    for (int i=0; i<n-1; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> w;
            int u = id(i, j);
            int v = id(i+1, j);
            adj[u].insert({v, w});
            adj[v].insert({u, w});
        }
    }
    solution(adj);
    return 0;
}