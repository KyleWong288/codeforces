#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;

int N, M, start, finish;

// path should be chunks of the same colored edges
// never have something like [red, blue, red] since there exists a path between all reds, so that blue is unnecessary
// so bfs by color: queue tracks nodes, visited tracks colors and nodes
// add: for each unvisited edge color, mark that color, then add and mark all the unvisited nodes in that color
int solve(vector<vector<int>>& edges) {
    // stores <color, list of nodes with an edge of that color>
    map<int, vector<int>> colMap;
    // stores <to, color of edge>
    vector<vector<vector<int>>> adj(N);
    for (auto& e : edges) {
        int u = e[0]-1, v = e[1]-1, c = e[2];
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
        colMap[c].push_back(u);
        colMap[c].push_back(v);
    }
    int res = 0;
    map<int,int> visC;
    vector<int> vis(N, 0);
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    while (q.size()) {
        int sz = q.size();
        while (sz--) {
            int cur = q.front();
            q.pop();
            if (cur == finish) return res;
            for (auto& e : adj[cur]) {
                int to = e[0], color = e[1];
                if (visC[color]) continue;
                visC[color] = 1;
                for (auto& u : colMap[color]) {
                    if (vis[u]) continue;
                    vis[u] = 1;
                    q.push(u);
                }
            }
        }
        ++res;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<vector<int>> edges(M, vector<int>(3));
        for (auto& e : edges) {
            cin >> e[0] >> e[1] >> e[2];
        }
        cin >> start >> finish;
        start--;
        finish--;
        res[i] = solve(edges);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}