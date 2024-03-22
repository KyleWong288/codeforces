#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

ll N, M, K, D;

ll getCost(vector<int>& row) {
    // dp[i] = min cost placing support at i
    vector<ll> dp(M, 1e18);
    dp[0] = 1;
    // tracks the values in dp[i-D, D]
    multiset<ll> rmq;
    rmq.insert(1);
    for (int i=1; i<M; ++i) {
        if (i >= D + 2) {
            ll delVal = dp[i - D - 2];
            auto it = rmq.find(delVal);
            rmq.erase(it);
        }
        ll best = *rmq.begin();
        dp[i] = best + row[i] + 1;
        rmq.insert(dp[i]);
    }
    return dp[M-1];
}

// each row is independent, sliding window sum
// use dp to compute best score for each row: dp[i] = min cost placing a support at i
// range min query from [i-d, i], just use multiset
ll solve(vector<vector<int>>& g) {
    vector<ll> cost(N);
    for (int i=0; i<N; ++i) {
        cost[i] = getCost(g[i]);
    }
    ll sum = 0;
    for (int i=0; i<K; ++i) {
        sum += cost[i];
    }
    ll res = sum;
    for (int i=K; i<N; ++i) {
        sum -= cost[i-K];
        sum += cost[i];
        res = min(res, sum);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M >> K >> D;
        vector<vector<int>> g(N, vector<int>(M));
        for (int r=0; r<N; ++r) {
            for (int c=0; c<M; ++c) {
                cin >> g[r][c];
            }
        }
        res[i] = solve(g);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}