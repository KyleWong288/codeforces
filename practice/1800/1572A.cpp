#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

int N;

// top sort duh, kahns for top sort and cycle detection
// 1 -> 3, we can read both at the same time since 1 < 3
// 4 -> 3, we need a new iteration since 4 > 3
// how to differentiate when bfsing? use a pq and store <time, book id>, conveniently also reads book id in proper order
int solution(vector<vector<int>>& adj) {
    int res = 0;
    vector<int> indeg(N+1, 0);
    for (int i=1; i<=N; ++i) {
        for (auto& to : adj[i]) {
            indeg[to]++;
        }
    }
    // pq stores <time, book id>
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    for (int i=1; i<=N; ++i) {
        if (!indeg[i]) {
            pq.push({1, i});
        }
    }
    while (pq.size()) {
        int t = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        res = t;
        for (auto& to : adj[cur]) {
            indeg[to]--;
            if (!indeg[to]) {
                to > cur ? pq.push({t, to}) : pq.push({t+1, to});
            }
        }
    }
    // check everything reached:
    for (auto& x : indeg) {
        if (x) { return -1; }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int sz, u;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<vector<int>> adj(N+1);
        for (int j=1; j<=N; ++j) {
            cin >> sz;
            while (sz--) {
                cin >> u;
                adj[u].push_back(j);
            }
        }
        res[i] = solution(adj);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}