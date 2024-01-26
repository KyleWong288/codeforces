#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;

// straightforward dp: to make length i, add one R (look at i-1) or add K Ws (look at i-k)
// dp[i] = dp[i-1] + dp[i-k]
// then prefix sum and answer range queries
vector<ll> solution(int k) {
    // dp[i] = # of valid sequences of length i
    vector<ll> dp(1e5+1, 0);
    dp[0] = 1;
    for (int i=1; i<=1e5; ++i) {
        dp[i] += dp[i-1];
        if (i - k >= 0) {
            dp[i] += dp[i-k];
        }
        dp[i] %= MOD;
    }
    // convert to psum
    for (int i=1; i<=1e5; ++i) {
        dp[i] += dp[i-1];
        dp[i] %= MOD;
    }
    return dp;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, K, a, b;
    cin >> T >> K;
    vector<ll> pref = solution(K);
    while (T--) {
        cin >> a >> b;
        ll res = (pref[b] - pref[a-1] + MOD) % MOD;
        cout << res << endl;
    }
    return 0;
}