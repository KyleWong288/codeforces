#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, Q;

// 2d prefix sum, find all rectangles between (hs, hb) and (ws, wb)
vector<ll> solution(vector<vector<ll>>& rects, vector<vector<ll>>& queries) {
    // construct 2d prefix sum, dp[i][j] = sum of areas of rectangles from [0,0] to [i,j]
    vector<vector<ll>> dp(1001, vector<ll>(1001, 0));
    for (auto& rect : rects) {
        int h = rect[0];
        int w = rect[1];
        ++dp[h][w];
    }
    for (int i=1; i<=1000; ++i) {
        for (int j=1; j<=1000; ++j) {
            dp[i][j] *= (i * j);
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    // answer queries:
    vector<ll> res(Q, 0);
    int hs, ws, hb, wb;
    for (int i=0; i<Q; ++i) {
        hs = queries[i][0], ws = queries[i][1], hb = queries[i][2]-1, wb = queries[i][3]-1;
        res[i] = dp[hb][wb] - dp[hs][wb] - dp[hb][ws] + dp[hs][ws];
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    vector<vector<ll>> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> Q;
        vector<vector<ll>> rects(N, vector<ll>(2));
        for (auto& x : rects) {
            cin >> x[0] >> x[1];
        }
        vector<vector<ll>> queries(Q, vector<ll>(4));
        for (auto& x : queries) {
            cin >> x[0] >> x[1] >> x[2] >> x[3];
        }
        res[i] = solution(rects, queries);
    }
    for (auto& r : res) {
        for (auto& x : r) {
            cout << x << endl;
        }
    }
    return 0;
}