#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

int far, diam;

// finds the distance and farthest node from start
void dfsFar(vector<vector<int>>& adj, int cur, int par, int depth) {
    if (depth > diam) {
        diam = depth;
        far = cur;
    }
    for (auto& to : adj[cur]) {
        if (to != par) {
            dfsFar(adj, to, cur, depth+1);
        }
    }
}

// points in the center gradually lose edges until they become their own cc
// find tree diameter, then find points in tree center, then bfs outwards
void solution(vector<vector<int>>& adj, int N) {
    vector<int> res(N+1, 0);
    // get tree diameter:
    diam = 0;
    dfsFar(adj, 1, -1, 0);
    int far1 = far;
    diam = 0;
    dfsFar(adj, far, -1, 0);
    int far2 = far;
    // push centers into main q by bfsing on far1 and far2:
    vector<bool> vis(N+1, 0);
    vector<bool> vis1(N+1, 0);
    vector<bool> vis2(N+1, 0);
    queue<int> q, q1, q2;
    q1.push(far1);
    q2.push(far2);
    vis1[far1] = 1, vis2[far2] = 1;
    while (true) {
        int sz1 = q1.size();
        int sz2 = q2.size();
        bool meet = 0;
        // bfs from far1
        while (sz1--) {
            int cur = q1.front();
            q1.pop();
            for (auto& to : adj[cur]) {
                if (vis2[to]) {
                    meet = 1;
                    q.push(to);
                    vis[to] = 1;
                }
                if (vis1[to] == 0) {
                    vis1[to] = 1;
                    q1.push(to);
                }
            }
        }
        // bfs from far2
        while (sz2--) {
            int cur = q2.front();
            q2.pop();
            for (auto& to : adj[cur]) {
                if (vis1[to]) {
                    meet = 1;
                    q.push(to);
                    vis[to] = 1;
                }
                if (vis2[to] == 0) {
                    vis2[to] = 2;
                    q2.push(to);
                }
            }
        }
        if (meet) { break; }
    }
    // bfs from centers:
    int k = diam / 2 + diam % 2;
    for (int i=1; i<=k; ++i) {
        res[i] = 1;
    }
    for (int i=k+1; i<=N; ++i) {
        int sz = q.size();
        res[i] = min(N, res[i-1] + sz);
        while (sz--) {
            int cur = q.front();
            q.pop();
            for (auto& to : adj[cur]) {
                if (!vis[to]) {
                    q.push(to);
                    vis[to] = 1;
                }
            }
        }
    }
    for (int i=1; i<=N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, u, v;
    cin >> N;
    vector<vector<int>> adj(N+1);
    for (int i=0; i<N-1; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solution(adj, N);
    return 0;
}