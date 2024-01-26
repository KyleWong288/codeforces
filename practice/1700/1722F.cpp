#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M;

// clears the cells in L, also checks neighbors for each cell
bool checkNear(vector<vector<bool>>& grid, vector<pair<int,int>>& cells) {
    for (auto& pr : cells) {
        grid[pr.first][pr.second] = 0;
    }
    for (auto& pr : cells) {
        int r = pr.first;
        int c = pr.second;
        for (int dr=-1; dr<=1; ++dr) {
            for (int dc=-1; dc<=1; ++dc) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr >= 0 && nr < N && nc >= 0 && nc < M && grid[nr][nc]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// if we find *, there are 4 possible ways it can be the "pivot" of a valid L
// if we find a L, clear the space and then check the surrounding space
int solution(vector<vector<bool>>& grid) {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (grid[i][j]) {
                // stores the <row, col> for each cell in L
                vector<pair<int,int>> cells;
                cells.push_back({i,j});
                if (i < N-1 && j < M-1 && grid[i+1][j] && grid[i+1][j+1]) { // type 1
                    cells.push_back({i+1, j});
                    cells.push_back({i+1, j+1});
                }
                if (i < N-1 && j > 0 && grid[i+1][j] && grid[i+1][j-1]) { // type 2
                    cells.push_back({i+1, j});
                    cells.push_back({i+1, j-1});
                }
                if (i < N-1 && j < M-1 && grid[i][j+1] && grid[i+1][j+1]) { // type 3
                    cells.push_back({i, j+1});
                    cells.push_back({i+1, j+1});
                }
                if (i < N-1 && j < M-1 && grid[i][j+1] && grid[i+1][j]) { // type 4
                    cells.push_back({i, j+1});
                    cells.push_back({i+1, j});
                }
                if (cells.size() != 3) {
                    return 0;
                }
                bool near = checkNear(grid, cells);
                if (near) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    char ch;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<vector<bool>> grid(N, vector<bool>(M, 0));
        for (int r=0; r<N; ++r) {
            for (int c=0; c<M; ++c) {
                cin >> ch;
                if (ch == '*') {
                    grid[r][c] = 1;
                }
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