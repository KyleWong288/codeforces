#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

int N, M, og, used;
set<int> pathSet;

// returns true if cycle containing og
bool dfs(vector<vector<int>>& adj, vector<bool>& vis, int cur, int par) {
    if (vis[cur]) {
        return (cur == og);
    }
    vis[cur] = 1;
    bool res = 0;
    for (auto& to : adj[cur]) {
        if (to != par) {
            res = res || dfs(adj, vis, to, cur);
        }
    }
    return res;
}

// gets the actual cycle, tracks the # of vertices conected to og and stops once it hits 2
void dfsGet(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& conU, vector<int>& path, int cur, int par) {
    if (vis[cur] || used == 2) {
        return;
    }
    vis[cur] = 1;
    path.push_back(cur);
    pathSet.insert(cur);
    used += conU[cur];
    // we have the ideal cycle, just get tail edges
    if (used == 2) {
        for (auto& to : adj[og]) {
            if (used >= 4) break;
            if (pathSet.find(to) == pathSet.end()) {
                ++used;
                path.push_back(to);
            }
        }
        return;
    }
    for (auto& to : adj[cur]) {
        dfsGet(adj, vis, conU, path, to, cur);
        if (used >= 2) return;
    }
    path.pop_back();
    pathSet.erase(cur);
    used -= conU[cur];
}

// good?? if a vertex is part of a cycle and has degree >= 4 its good
// bad?? what if the other edges connect to vertices that are part of the cycle?
// this is fine, if such edges exist, they create a smaller subcycle, and then one of the original edges can be a tail
// so we just need degree and if a vertex is part of any cycle, brute forcable
// getting a valid cycle is also tricky, make sure you use exactly two edges that connect to u
void solve(vector<vector<int>>& adj, vector<int>& deg) {
    pathSet.clear();
    for (int i=1; i<=N; ++i) {
        og = i;
        vector<bool> vis(N+1, 0);
        bool hasCycle = dfs(adj, vis, i, -1);
        if (hasCycle && deg[i] >= 4) {
            cout << "YES" << endl;
            // finds the actual edges used:
            used = 0;
            vector<bool> conU(N+1, 0);
            for (auto& to : adj[i]) {
                conU[to] = 1;
            }
            vector<bool> vis(N+1, 0);
            // first elements are cycle, last 2 elements are tails connected to og
            vector<int> path;
            dfsGet(adj, vis, conU, path, og, -1);
            int len = path.size();
            cout << len << endl;
            for (int i=0; i<len-3; ++i) {
                cout << path[i] << " " << path[i+1] << endl;
            }
            cout << path[len-3] << " " << og << endl;
            cout << og << " " << path[len-2] << endl;
            cout << og << " " << path[len-1] << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int u, v;
    while (T--) {
        cin >> N >> M;
        vector<vector<int>> adj(N+1);
        vector<int> deg(N+1, 0);
        for (int i=0; i<M; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        solve(adj, deg);
    }
    return 0;
}