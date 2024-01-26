#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

vector<int> dr = {1, -1, 0, 0};
vector<int> dc = {0, 0, 1, -1};

void dfs(vector<vector<char>>& grid, int r, int c) {
    int n = grid.size();
    int m = grid[0].size();
    if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == '#' || grid[r][c] == 'V') {
        return;
    }
    grid[r][c] = 'V';
    for (int mv=0; mv<4; ++mv) {
        dfs(grid, r + dr[mv], c + dc[mv]);
    }
}

// If G and B adjacent, auto fail
// For a path from G->E, each cell in this path must not border a B. Enforce this by padding each B with a wall in all 4 directions
// Then dfs from exit to see if we can reach all G
int solution(vector<vector<char>>& grid, int n, int m) {
    // add padding to each B:
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (grid[i][j] != 'B') { continue; }
            for (int mv=0; mv<4; ++mv) {
                int nr = i + dr[mv];
                int nc = j + dc[mv];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if (grid[nr][nc] == 'G') {
                        return 0;
                    }
                    if (grid[nr][nc] != 'B') {
                        grid[nr][nc] = '#';
                    }
                }
            }
        }
    }
    // dfs from exit:
    dfs(grid, n-1, m-1);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (grid[i][j] == 'G') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, N, M;
    cin >> T;
    vector<int> res(T);
    string line;
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<vector<char>> grid(N, vector<char>(M));
        for (int r=0; r<N; ++r) {
            cin >> line;
            for (int c=0; c<M; ++c) {
                grid[r][c] = line[c];
            }
        }
        res[i] = solution(grid, N, M);
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