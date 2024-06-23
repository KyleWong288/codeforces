#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M;

// find the 4 tips: unique left x, right x, top y, bottom y
void solve(vector<vector<char>>& grid) {
    int lx = M, rx = 0, ty = N, by = 0;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (grid[i][j] == '#') {
                lx = min(lx, j);
                rx = max(rx, j);
                ty = min(ty, i);
                by = max(by, i);
            }
        }
    }
    int midC = (lx + rx + 2) / 2;
    int midR = (ty + by + 2) / 2;
    cout << midR << " " << midC << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
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