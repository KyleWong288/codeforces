#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int solution(vector<vector<int>>& pts) {
    int xl = 2e9;
    int xr = -2e8;
    int yl = 2e9;
    int yr = -2e9;
    for (auto& p : pts) {
        xl = min(xl, p[0]);
        xr = max(xr, p[0]);
        yl = min(yl, p[1]);
        yr = max(yr, p[1]);
    }
    int res = (yr - yl) * (xr - xl);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        vector<vector<int>> pts(4, vector<int>(2));
        for (int j=0; j<4; ++j) {
            cin >> pts[j][0] >> pts[j][1];
        }
        res[i] = solution(pts);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}