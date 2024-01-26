#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <unordered_set>
using namespace std;

int N, A, B;
int U;
bool cycFound;
unordered_set<int> cycle;

void visReset(vector<bool>& vis) {
    for (int i=0; i<vis.size(); ++i) {
        vis[i] = 0;
    }
}

// marks all cycle vertices in cycle
void markCyc(vector<vector<int>>& adj, vector<int>& path, unordered_set<int>& have, int cur, int par) {
    if (have.find(cur) != have.end()) { // loop found, mark cycle nodes on path
        while (path.back() != cur) {
            cycle.insert(path.back());
            path.pop_back();
        }
        cycle.insert(cur);
        cycFound = 1;
        return;
    }
    path.push_back(cur);
    have.insert(cur);
    for (auto& neigh : adj[cur]) {
        if (neigh != par) {
            markCyc(adj, path, have, neigh, cur);
        }
        if (cycFound) {
            return;
        }
    }
    path.pop_back();
    have.erase(cur);
}

// finds shortest path from B to any cycle vertex
int bfsB(vector<vector<int>>& adj, vector<bool>& vis) {
    queue<int> q;
    q.push(B);
    vis[B] = 1;
    int len = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int cur = q.front();
            q.pop();
            if (cycle.find(cur) != cycle.end()) {
                U = cur;
                return len;
            }
            for (auto& neigh : adj[cur]) {
                if (!vis[neigh]) {
                    vis[neigh] = 1;
                    q.push(neigh);
                }
            }
        }
        ++len;
    }
    return 1e9;
}

// finds shortest path from A to U
int bfsA(vector<vector<int>>& adj, vector<bool>& vis) {
    queue<int> q;
    q.push(A);
    vis[A] = 1;
    int len = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int cur = q.front();
            q.pop();
            if (cur == U) {
                return len;
            }
            for (auto& neigh : adj[cur]) {
                if (!vis[neigh]) {
                    vis[neigh] = 1;
                    q.push(neigh);
                }
            }
        }
        ++len;
    }
    return 1e9;
}

// tree with extra path, so exactly one cycle
// find if V can reach the cycle before intersecting with M
// 1. mark all cycle vertices
// 2. find sssp from B to any cycle vertex U -> len p
// 3. find shortest path from A to U -> len q
// 4. need q < p
int solution(vector<vector<int>>& adj) {
    cycFound = 0;
    vector<int> path;
    unordered_set<int> have;
    cycle.clear();
    markCyc(adj, path, have, 1, 0);
    vector<bool> vis(N+1, 0);
    int lenA = bfsB(adj, vis);
    visReset(vis);
    int lenB = bfsA(adj, vis);
    if (lenA < lenB) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int T, u, v;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> A >> B;
        vector<vector<int>> adj(N+1);
        for (int j=0; j<N; ++j) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        res[i] = solution(adj);
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