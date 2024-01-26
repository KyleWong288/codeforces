#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <numeric>
using namespace std;

int N, M;

// only fails when total is not divisible by N
// pair extra array with fewer array: extra array always has some set bit the fewer array doesn't have, so swapping always works
void solution(vector<vector<int>>& grid) {
    int goal = 0;
    for (auto& row : grid) {
        for (auto& x : row) {
            goal += x;
        }
    }
    if (goal % N) {
        cout << -1 << endl;
        return;
    }
    goal /= N;
    // over[i] = how much over goal each array has
    vector<int> over(N, 0);
    // extra[i] = list of all extra arrays that have bit i set
    vector<vector<int>> extra(M);
    for (int i=0; i<N; ++i) {
        int sum = accumulate(grid[i].begin(), grid[i].end(), 0);
        over[i] = sum - goal;
        if (over[i] > 0) {
            for (int j=0; j<M; ++j) {
                if (grid[i][j]) {
                    extra[j].push_back(i);
                }
            }
        }
    }
    vector<vector<int>> res;
    for (int i=0; i<N; ++i) {
        if (over[i] >= 0) { continue; }
        for (int j=0; j<M; ++j) {
            if (grid[i][j]) { continue; }
            while (!extra[j].empty()) {
                int row = extra[j].back();
                if (over[row] <= 0) {
                    extra[j].pop_back();
                }
                else {
                    --over[row];
                    ++over[i];
                    extra[j].pop_back();
                    res.push_back({i, row, j});
                    break;
                }
            }
            if (over[i] >= 0) { break; }
        }
    }
    cout << res.size() << endl;
    for (auto& r : res) {
        cout << r[0]+1 << " " << r[1]+1 << " " << r[2]+1 << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        vector<vector<int>> grid(N, vector<int>(M));
        for (int r=0; r<N; ++r) {
            for (int c=0; c<M; ++c) {
                cin >> grid[r][c];
            }
        }
        solution(grid);
    }
    return 0;
}