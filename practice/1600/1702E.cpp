#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int N;

// construct 2 sets of edges with no overlapping vertices
// bipartite check, even length cycles are fine, put every other edge in set 1, rest in set 2
int solution(vector<pair<int,int>>& edges) {
    // check 2 of each:
    vector<int> freq(N+1, 0);
    for (auto& e : edges) {
        freq[e.first]++;
        freq[e.second]++;
        if (freq[e.first] > 2 || freq[e.second] > 2) {
            return 0;
        }
    }
    // bipartite check with bfs:
    vector<vector<int>> adj(N+1);
    for (auto& e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }
    vector<int> vis(N+1, 0);
    for (int i=1; i<=N; ++i) {
        if (!vis[i]) {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty()) {
                int sz = q.size();
                while (sz--) {
                    int u = q.front();
                    int c = vis[u];
                    q.pop();
                    for (auto& v : adj[u]) {
                        if (vis[v] == c) {
                            return 0;
                        }
                        if (vis[v] == 0) {
                            vis[v] = -1 * c;
                            q.push(v);
                        }
                    }
                }
            }
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<pair<int,int>> edges(N);
        for (auto& e : edges) {
            cin >> e.first >> e.second;
        }
        res[i] = solution(edges);
    }
    for (auto& r : res) {
        if (r) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}