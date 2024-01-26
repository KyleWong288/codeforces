#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int N, K;

void dfs(vector<vector<int>>& adj, vector<ll>& costs, vector<bool>& vis, int cur) {
    if (vis[cur] || adj[cur].empty()) {
        return;
    }
    vis[cur] = true;
    ll sum = 0;
    for (auto& neigh : adj[cur]) {
        dfs(adj, costs, vis, neigh);
        sum += costs[neigh];
    }
    costs[cur] = min(sum, costs[cur]);
}

// dp, cheapest way to make x is sum of cheapest ways to make children of x
vector<ll> solution(vector<vector<int>>& adj, vector<ll>& costs) {
    // stores potion types of current layer
    vector<bool> vis(N+1, 0);
    for (int i=1; i<=N; ++i) {
        dfs(adj, costs, vis, i);
    }
    vector<ll> res(N);
    for (int i=1; i<=N; ++i) {
        res[i-1] = costs[i];
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    int v, m;
    vector<vector<ll>> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
        // init costs
        vector<ll> costs(N+1);
        for (int j=1; j<=N; ++j) {
            cin >> costs[j];
        }
        // unlimited supply means free
        for (int j=0; j<K; ++j) {
            cin >> v;
            costs[v] = 0;
        }
        // build graph for dp
        vector<vector<int>> adj(N+1);
        for (int u=1; u<=N; ++u) {
            cin >> m;
            for (int j=0; j<m; ++j) {
                cin >> v;
                adj[u].push_back(v);
            }
        }
        res[i] = solution(adj, costs);
    }
    for (auto& r : res) {
        for (auto& x : r) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}