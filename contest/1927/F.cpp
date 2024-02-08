#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M;

vector<int> rk;
vector<int> par;

int find(int cur) {
    int v = cur;
    while (v != par[v]) {
        v = par[v];
    }
    par[cur] = v;
    return v;
}

// returns 1 if u and v already in same cc
int join(int u, int v) {
    int parU = find(u);
    int parV = find(v);
    if (parU == parV) {
        return 1;
    }
    if (rk[parU] > rk[parV]) {
        par[parV] = parU;
    }
    else if (rk[parU] < rk[parV]) {
        par[parU] = parV;
    }
    else {
        rk[parU]++;
        par[parV] = parU;
    }
    return 0;
}

// track path starting from u, stops once we hit v
void dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& path, int cur, int goal) {
    if (vis[cur] || vis[goal]) return;
    vis[cur] = 1;
    path.push_back(cur);
    for (auto& to : adj[cur]) {
        dfs(adj, vis, path, to, goal);
        if (vis[goal]) return;
    }
    path.pop_back();
}

// dsu edges in reverse sorted order, pick the edge E that causes a cycle with min weight
// how to get the cycle with E?
// E connects (u, v). Remove E. Dfs(u) to reach v, then this path + E is a cycle with E. 
void solve(vector<vector<int>>& edges) {
    // reset dsu:
    rk.clear();
    par.clear();
    rk.resize(N+1, 0);
    par.resize(N+1, 0);
    for (int i=1; i<=N; ++i) {
        par[i] = i;
    }
    // find min weight edge causing cycle:
    int minW = 1e9;
    int u = -1, v = -1;
    sort(edges.rbegin(), edges.rend());
    for (auto& e : edges) {
        int cycle = join(e[1], e[2]);
        if (cycle) {
            u = e[1], v = e[2], minW = e[0];
        }
    }
    // build graph and dfs:
    vector<vector<int>> adj(N+1);
    for (auto& e : edges) {
        if ((e[1] == u && e[2] == v) || (e[1] == v && e[2] == u)) continue;
        adj[e[1]].push_back(e[2]);
        adj[e[2]].push_back(e[1]);
    }
    vector<int> path;
    vector<bool> vis(N+1, 0);
    dfs(adj, vis, path, u, v);
    // cout << "RES:" << endl;
    cout << minW << " " << path.size() << endl;
    for (auto& node : path) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int u, v, w;
    while (T--) {
        cin >> N >> M;
        vector<vector<int>> edges(M);
        for (int i=0; i<M; ++i) {
            cin >> u >> v >> w;
            edges[i] = {w, u, v};
        }
        solve(edges);
    }
    return 0;
}