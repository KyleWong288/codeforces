#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

ll N, K;

// we can take at most 32 bad keys before everything is 0
// dp[i][j] = max coins on index i using j bad keys, taking i as bad key looks at dp[i-1][j-1], taking i as good key looks at dp[i-1][j]
ll solution(vector<ll>& v) {
    vector<vector<ll>> dp(N, vector<ll>(32, -1e16));
    // base case, first row:
    dp[0][0] = v[0] - K;
    dp[0][1] = v[0] / 2;
    ll res = max(dp[0][0], dp[0][1]);
    // regular dp:
    for (int i=1; i<N; ++i) {
        for (int j=0; j<min(32,i+2); ++j) {
            if (j == 0) {
                dp[i][j] = dp[i-1][j] + v[i] - K;
            }
            else {
                ll good = dp[i-1][j] + v[i] / (1 << j) - K;
                ll bad = dp[i-1][j-1] + v[i] / (1 << j);
                dp[i][j] = max(good, bad);
            }
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
        vector<ll> v(N);
        for (auto& x : v) {
            cin >> x;
        }
        res[i] = solution(v);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}