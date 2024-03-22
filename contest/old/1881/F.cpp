#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_set>
using namespace std;
typedef long long ll;

int N, K;
int maxDist;
int far;

// returns if theres a marked vertex in a subtree, if theres not, prune that edge
bool pruneDfs(vector<unordered_set<int>>& adj, vector<bool>& mark, int cur, int par) {
    bool res = mark[cur];
    vector<int> del;
    for (auto& to : adj[cur]) {
        if (to == par) { continue; }
        bool hasMark = pruneDfs(adj, mark, to, cur);
        if (hasMark) {
            res = 1;
        }
        else {
            del.push_back(to);
        }
    }
    for (auto& x : del) {
        adj[cur].erase(x);
    }
    return res;
}

// finds furthest node from starting point and stores the distance
void farDfs(vector<unordered_set<int>>& adj, int cur, int par, int dep) {
    if (dep > maxDist) {
        maxDist = dep;
        far = cur;
    }
    for (auto& to : adj[cur]) {
        if (to == par) { continue; }
        farDfs(adj, to, cur, dep+1);
    }
}

// prune the graph, cut off subtrees with no marked vertices
// find the tree diameter on the pruned graph
int solution(vector<unordered_set<int>>& adj, vector<bool>& mark) {
    // start prune on a marked vertex
    int start = 0;
    for (int i=1; i<=N; ++i) {
        if (mark[i]) {
            start = i;
            break;
        }
    }
    pruneDfs(adj, mark, start, -1);
    maxDist = -1, far = -1;
    // get one end of tree diameter
    farDfs(adj, start, -1, 0);
    // get other end of tree diameter
    start = far;
    maxDist = -1;
    farDfs(adj, start, -1, 0);
    int res = (maxDist / 2) + (maxDist % 2);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, u, v;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
        vector<bool> marked(N+1, 0);
        for (int j=0; j<K; ++j) {
            cin >> u;
            marked[u] = 1;
        }
        vector<unordered_set<int>> adj(N+1);
        for (int j=0; j<N-1; ++j) {
            cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        res[i] = solution(adj, marked);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}