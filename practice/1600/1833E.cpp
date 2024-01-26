#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_set>
using namespace std;

int N;

// returns if the dfs on this cc is a cycle of size > 2
bool dfs(vector<unordered_set<int>>& adj, vector<bool>& vis, int cur, int par) {
    if (vis[cur]) {
        return 1;
    }
    bool res = 0;
    vis[cur] = 1;
    for (auto& to : adj[cur]) {
        if (to != par) {
            res |= dfs(adj, vis, to, cur);
        }
    }
    return res;
}

// construct graph of neighbors, cyclic ccs of size > 2 are fixed, non cyclic ccs can be merged
// min: # of cyclic ccs, add 1 if non cyclic ccs exist
// max: # of ccs
// adj uses a set to avoid duplicate edges from undirected construction
pair<int,int> solution(vector<unordered_set<int>>& adj) {
    int numCycles = 0;
    int numCcs = 0;
    int noCycle = 0;
    vector<bool> vis(N+1, 0);
    for (int i=1; i<=N; ++i) {
        if (!vis[i]) {
            bool isCycle = dfs(adj, vis, i, 0);
            numCycles += isCycle;
            if (!isCycle) {
                noCycle = 1;
            }
            ++numCcs;
        }
    }
    return {numCycles + noCycle, numCcs};
}

int main() {
    int T, v;
    cin >> T;
    vector<pair<int,int>> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<unordered_set<int>> adj(N+1);
        for (int u=1; u<=N; ++u) {
            cin >> v;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        res[i] = solution(adj);
    }
    for (auto& r : res) {
        cout << r.first << " " << r.second << endl;
    }
    return 0;
}