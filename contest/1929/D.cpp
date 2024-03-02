#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
int N;
ll res = 0;


void dfs(vector<vector<int>>& adj, vector<ll>& dp, int cur, int par) {
    ll ways = 1;
    // compute dp, how many ways if cur and its subtree contain the 2nd bad node:
    for (auto& to : adj[cur]) {
        if (to == par) continue;
        dfs(adj, dp, to, cur);
        ways = (ways * dp[to]) % MOD;
    }
    ways += 1; // mark me, invalidates all children
    // compute contribution to global res, how much does cur add if cur is the 1st bad node:
    int children = 0;
    for (auto& to : adj[cur]) {
        if (to == par) continue;
        res = (res + dp[to]) % MOD;
        ++children;
    }
    res = (res - children + MOD) % MOD;
    dp[cur] = ways;
}

// dp as if its the 2nd bad node in the path
// add to global sum as if its the 1st bad node in the path
int solve(vector<vector<int>>& edges) {
    res = 0;
    vector<vector<int>> adj(N+1);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    // dp[i] = # of subsets in the subtree rooted at i such that using that subset allows you to mark some parent as bad
    vector<ll> dp(N+1, 0);
    dfs(adj, dp, 1, -1);
    res = (res + dp[1]) % MOD;    // this actually accounts for the unmarked tree   
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<vector<int>> edges(N-1, vector<int>(2));
        for (auto& e : edges) {
            cin >> e[0] >> e[1];
        }
        res[i] = solve(edges);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}