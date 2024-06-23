#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

int N, M;
vector<int> dr = {1,-1,0,0};
vector<int> dc = {0,0,1,-1};

// maps row to ccs that use this row
map<int,vector<int>> rowCcs;
// maps col to ccs that use this col
map<int,vector<int>> colCcs;
// maps cc to size
map<int,int> ccSize;

void dfs(vector<vector<char>>& grid, int r, int c, int& size, set<int>& rUsed, set<int>& cUsed) {
    ++size;
    rUsed.insert(r);
    cUsed.insert(c);
    grid[r][c] = 'x';
    for (int mv=0; mv<4; ++mv) {
        int nr = r + dr[mv];
        int nc = c + dc[mv];
        if (nr >= 0 && nr < N && nc >= 0 && nc < M && grid[nr][nc] == '#') {
            dfs(grid, nr, nc, size, rUsed, cUsed);
        }
    }
}

// add row op: connects all ccs that use row r, r-1, r+1
// add col op: connects all ccs that use col c, c-1, c+1
void solve(vector<vector<char>>& grid) {
    // get row/col counts 
    vector<int> rowCount(N, 0);
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            rowCount[i] += (grid[i][j] == '#');
        }
    }
    vector<int> colCount(M, 0);
    for (int j=0; j<M; ++j) {
        for (int i=0; i<N; ++i) {
            colCount[j] += (grid[i][j] == '#');
        }
    }
    // get cc sizes
    int ccid = 0;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (grid[i][j] != '#') continue;
            int size = 0;
            set<int> rowsUsed;
            set<int> colsUsed;
            dfs(grid, i, j, size, rowsUsed, colsUsed);
            for (auto& row : rowsUsed) {
                rowCcs[row].push_back(ccid);
            }
            for (auto& col : colsUsed) {
                colCcs[col].push_back(ccid);
            }
            ccSize[ccid++] = size;
        }
    }
    int res = 0;
    // try all rows:
    for (int i=0; i<N; ++i) {
        set<int> ccsUse;
        if (i > 0) for (auto& cc : rowCcs[i-1]) ccsUse.insert(cc);
        for (auto& cc : rowCcs[i]) ccsUse.insert(cc);
        if (i < N-1) for (auto& cc : rowCcs[i+1]) ccsUse.insert(cc);
        int sum = 0;
        for (auto& cc : ccsUse) sum += ccSize[cc];
        res = max(res, sum + M - rowCount[i]);
    }
    // try all cols: 
    for (int i=0; i<M; ++i) {
        set<int> ccsUse;
        if (i > 0) for (auto& cc : colCcs[i-1]) ccsUse.insert(cc);
        for (auto& cc : colCcs[i]) ccsUse.insert(cc);
        if (i < M-1) for (auto& cc : colCcs[i+1]) ccsUse.insert(cc);
        int sum = 0;
        for (auto& cc : ccsUse) sum += ccSize[cc];
        res = max(res, sum + N - colCount[i]);
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        rowCcs.clear();
        colCcs.clear();
        ccSize.clear();
        vector<vector<char>> grid(N, vector<char>(M));
        for (auto& row : grid) {
            for (auto& x : row) {
                cin >> x;
            }
        }
        solve(grid);
    }
    return 0;
}