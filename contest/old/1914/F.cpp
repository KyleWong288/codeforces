#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

int N;

// get depth for each vertex
void dfs(vector<vector<int>>& adj, vector<int>& depth, int cur, int d) {
    if (depth[cur] != -1) {
        return;
    }
    depth[cur] = d;
    for (auto& to : adj[cur]) {
        dfs(adj, depth, to, d+1);
    }
}

// handle cycles? no cycles!
// greedily pair by depth??? i think... use pq for depth
// topsort-ish, only push a parent when all children have been processed -> guarantees no pairs in the queue are in same path
int solution(vector<int>& par) {
    int res = 0;
    // build directed graph and get depth:
    vector<vector<int>> adj(N+1);
    for (int i=2; i<=N; ++i) {
        adj[par[i]].push_back(i);
    }
    vector<int> depth(N+1, -1);
    dfs(adj, depth, 1, 0);
    // build directed reverse graph and indeg for kahn:
    vector<int> rev(N+1);
    vector<int> indeg(N+1, 0);
    for (int i=2; i<=N; ++i) {
        rev[i] = par[i];
        indeg[par[i]]++;
    }
    // stores <depth, node>
    priority_queue<pair<int,int>> pq;
    for (int i=1; i<=N; ++i) {
        if (indeg[i] == 0) {
            pq.push({depth[i], i});
        }
    }
    while (pq.size() > 1) {
        int u = pq.top().second;
        pq.pop();
        int v = pq.top().second;
        pq.pop();
        int parU = rev[u];
        int parV = rev[v];
        indeg[parU]--;
        indeg[parV]--;
        if (indeg[parU] == 0) {
            pq.push({depth[parU], parU});
        }
        if (indeg[parV] == 0 && parU != parV) {
            pq.push({depth[parV], parV});
        }
        ++res;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> p(N+1);
        for (int j=2; j<=N; ++j) {
            cin >> p[j];
        }
        res[i] = solution(p);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}