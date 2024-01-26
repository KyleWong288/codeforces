#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int n,m,k;

// when i move from (r,c) to (r+1,c+1), add the 
int solve(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    int res = 0;
    vector<vector<int>> psRow(n, vector<int>(m+1, 0));
    vector<vector<int>> psCol(n+1, vector<int>(m, 0));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            psRow[i][j+1] = psRow[i][j] + grid[i][j];
        }
    }
    for (int j=0; j<m; ++j) {
        for (int i=0; i<n; ++i) {
            psCol[i+1][j] = psCol[i][j] + grid[i][j];
        }
    }

    cout << "PSROW:" << endl;
    for (auto& row : psRow) {
        for (auto& x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    cout << "PSCOL:" << endl;
    for (auto& row : psCol) {
        for (auto& x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    // type 1:
    for (int col=0; col<m; ++col) {
        int r = 0;
        int c = col;
        int sum = 0;
        // cout << "reset to " << r << " " << c << endl;
        while (r < n && c < m) {
            // cout << "adding " << (psRow[r][min(m, k+c)] - psRow[r][c]) << endl;
            sum += (psRow[r][min(m, k+c)] - psRow[r][c]);
            if (c) {
                // cout << "subbing " << (psCol[r][c-1] - psCol[max(0, r-k)][c-1]) << endl;
                sum -= (psCol[r][c-1] - psCol[max(0, r-k)][c-1]);
            }
            res = max(res, sum);
            // cout << r << " " << c << " " << sum << endl;
            ++r;
            ++c;
        }
    }
    return res;
}

// just solve for one direction, and rotate the grid 4 times
// i can only do rectangular queries and not triangle queries, how can i reduce to rectangular queries?
int solution(vector<vector<int>>& grid1) {
    int res = 0;
    vector<vector<int>> grid2(m, vector<int>(n));
    vector<vector<int>> grid3(n, vector<int>(m));
    vector<vector<int>> grid4(m, vector<int>(n));
    for (int r=0; r<n; ++r) {
        for (int c=0; c<m; ++c) {
            grid2[c][n-r-1] = grid1[r][c];
        }
    }
    for (int r=0; r<n; ++r) {
        for (int c=0; c<m; ++c) {
            grid3[n-r-1][m-c-1] = grid1[r][c];
        }
    }
    for (int r=0; r<m; ++r) {
        for (int c=0; c<n; ++c) {
            grid4[m-r-1][n-c-1] = grid2[r][c];
        }
    }
    res = max(res, solve(grid1));
    // res = max(res, solve(grid2));
    // res = max(res, solve(grid3));
    // res = max(res, solve(grid4));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    string row;
    for (int i=0; i<T; ++i) {
        cin >> n >> m >> k;
        ++k;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (int r=0; r<n; ++r) {
            cin >> row;
            for (int c=0; c<m; ++c) {
                grid[r][c] = (row[c] == '#');
            }
        }
        res[i] = solution(grid);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}