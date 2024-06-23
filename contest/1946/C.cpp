#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, K;
int m, cuts;

// returns size of the subtree rooted at cur
int dfs(vector<vector<int>>& adj, int cur, int par) {
    int res = 1;
    for (auto& to : adj[cur]) {
        if (to == par) continue;
        int subSize = dfs(adj, to, cur);
        if (subSize >= m && cuts < K) {
            ++cuts;
        }
        else {
            res += subSize;
        }
    }
    return res;
}

// bs on x, greedily cut a subtree as soon as it has size x
int solve(vector<vector<int>>& edges) {
    vector<vector<int>> adj(N);
    for (auto& e : edges) {
        int u = e[0]-1, v = e[1]-1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int l = 1;
    int r = N;
    while (l <= r) {
        m = (l + r) / 2;
        cuts = 0;
        int rootSz = dfs(adj, 0, -1);
        if (cuts >= K && rootSz >= m) {
            l = m+1;
        }
        else {
            r = m-1;
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
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