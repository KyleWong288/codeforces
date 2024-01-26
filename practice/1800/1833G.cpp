#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

int N, res;

int getEdgeId(map<pair<int,int>,int>& edgeMap, int u, int v) {
    pair<int,int> edge = {u, v};
    pair<int,int> revedge = {v, u};
    if (edgeMap.find(edge) != edgeMap.end()) {
        return edgeMap[edge];
    }
    else {
        return edgeMap[revedge];
    }
}

// 0 index paths, so same logic but shift values: n -> (n-1) % 3
int dfs(vector<vector<int>>& adj, map<pair<int,int>,int>& edgeMap, vector<int>& cuts, int cur, int par) {
    // stores <child val, child id>
    vector<pair<int,int>> childs;
    for (auto& to : adj[cur]) {
        if (to == par) { continue; }
        int c = dfs(adj, edgeMap, cuts, to, cur);
        if (c == 2) {
            int id = getEdgeId(edgeMap, cur, to);
            cuts.push_back(id);
        }
        else {
            childs.push_back({c, to});
        }
    }
    // leaf case:
    if (childs.empty()) {
        return 0;
    }
    // too many children case:
    else if (childs.size() > 2) {
        res = 0;
        return 1;
    }
    // 1 child case:
    else if (childs.size() == 1) {
        return childs[0].first + 1;
    }
    // 2 child case:
    else {
        if (childs[0].first == 0 && childs[1].first == 0) {
            return 2;
        }
        else {
            res = 0;
            return 1;
        }
    }
}

// bottom up dp, each child returns the length after using itself, and this value is unique (i think)
// fail case for parent with >2 child node: if we have >2 nonzero children, auto fail
// fail case for parent with 2 child node: (1, 2) or (2, 1) or (2, 2)
// also check that root returns 0
void solution(vector<vector<int>>& adj, map<pair<int,int>,int>& edgeMap) {
    // start from any leaf:
    int start = 0;
    for (int i=1; i<=N; ++i) {
        if (adj[i].size() == 1) {
            start = i;
            break;
        }
    }
    vector<int> cuts;
    res = 1;
    int root = dfs(adj, edgeMap, cuts, start, 0);
    if (root != 2) {
        res = 0;
    }
    if (res) {
        if (cuts.empty()) {
            cout << 0 << endl;
            cout << "" << endl;
        }
        else {
            cout << cuts.size() << endl;
            for (auto& c : cuts) {
                cout << c << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int u, v;
    while (T--) {
        cin >> N;
        vector<vector<int>> adj(N+1);
        map<pair<int,int>,int> edgeMap;
        for (int i=1; i<N; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edgeMap[make_pair(u, v)] = i;
        }
        solution(adj, edgeMap);
    }
    return 0;
}