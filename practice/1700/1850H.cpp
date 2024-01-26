#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

bool res;

const ll UNVIS = LLONG_MAX - 69;

int N, M;

void dfs(vector<vector<pair<ll,ll>>>& adj, vector<ll>& vis, int cur, ll spot) {
    if (!res) {
        return;
    }
    if (vis[cur] != UNVIS) {
        if (vis[cur] != spot) {
            res = false;
        }
        return;
    }
    vis[cur] = spot;
    for (auto& neigh : adj[cur]) {
        dfs(adj, vis, neigh.first, spot + neigh.second);
    }
}

// dfs and check contradictions, ccs are independent
bool solution(vector<vector<pair<ll,ll>>>& adj) {
    res = true;
    vector<ll> vis(N+1, UNVIS);
    for (int i=1; i<=N; ++i) {
        if (vis[i] == UNVIS) {
            dfs(adj, vis, i, 0);
        }
        if (!res) { 
            break;
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    ll u, v, w;
    vector<bool> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        // stores <to, weight>
        vector<vector<pair<ll,ll>>> adj(N+1);
        for (int j=0; j<M; ++j) {
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, -1 * w});
        }
        res[i] = solution(adj);
    }
    for (auto r : res) {
        if (r) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}