#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int n, k;

// spam one direction until the other direction becomes smaller, then swap
// cost monodec within a rectangle, so you full clear the best rect before moving to 2nd best rect, etc
int solve(vector<vector<int>>& rects) {
    int res = 0;
    int score = 0;
    // given rect[0] <= rect[1];
    sort(rects.begin(), rects.end());
    for (auto& rect : rects) {
        int h = rect[0], w = rect[1];
        while (h > 0 && w > 0) {
            if (h <= w) {
                res += h;
                --w;
            }
            else {
                res += w;
                --h;
            }
            if (++score == k) return res;
            // if (h > 0 && h <= w) {
            //     int goalW = h-1;
            //     int colsUsed = w - goalW;
            //     res += colsUsed * h;
            // }
            // if (w > 0 && w <= h) {

            // }
        }
        // count the last square taken twice
        if (++score == k) return res;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> k;
        vector<vector<int>> rects(n, vector<int>(2));
        for (auto& pr : rects) {
            int x, y;
            cin >> x >> y;
            pr[0] = min(x,y);
            pr[1] = max(x,y);
        }
        res[i] = solve(rects);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}