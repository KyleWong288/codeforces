#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

ll N, K, C;

void dfs(vector<vector<int>>& adj, vector<ll>& dist, int cur, int par, int depth) {
    dist[cur] = depth;
    for (auto& to : adj[cur]) {
        if (to != par) {
            dfs(adj, dist, to, cur, depth+1);
        }
    }
}

// using two nodes on the tree diameter, find the max node to node dist for each node
// also find the distance between the root and each node
ll solution(vector<vector<int>>& adj) {
    vector<ll> distRoot(N+1, 0);
    dfs(adj, distRoot, 1, -1, 0);
    int end = max_element(distRoot.begin(), distRoot.end()) - distRoot.begin();
    vector<ll> dist(N+1, 0);
    dfs(adj, dist, end, -1, 0);
    end = max_element(dist.begin(), dist.end()) - dist.begin();
    vector<ll> dist2(N+1, 0);
    dfs(adj, dist2, end, -1, 0);
    for (int i=0; i<=N; ++i) {
        dist[i] = max(dist[i], dist2[i]);
    }
    ll res = 0;
    for (int i=1; i<=N; ++i) {
        res = max(res, (dist[i] * K) - (distRoot[i] * C));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, u, v;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K >> C;
        vector<vector<int>> adj(N+1);
        for (int e=0; e<N-1; ++e) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        res[i] = solution(adj);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}