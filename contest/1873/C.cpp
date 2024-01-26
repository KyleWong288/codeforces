#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int solution(vector<string>& grid, vector<vector<int>>& pts) {
    int res = 0;
    for (int i=0; i<10; ++i) {
        for (int j=0; j<10; ++j) {
            if (grid[i][j] == 'X') {
                res += pts[i][j];
            }
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    vector<string> grid(10);
    // precompute points
    vector<vector<int>> pts(10, vector<int>(10, 1));
    for (int i=1; i<5; ++i) {
        // rows
        for (int j=i; j<10-i; ++j) {
            pts[i][j] = i+1;
            pts[10-i-1][j] = i+1;
        }
        // cols
        for (int j=i; j<10-i; ++j) {
            pts[j][i] = i+1;
            pts[j][10-i-1] = i+1;
        }
    }
    for (int i=0; i<T; ++i) {
        for (int j=0; j<10; ++j) {
            cin >> grid[j];
        }
        res[i] = solution(grid, pts);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}