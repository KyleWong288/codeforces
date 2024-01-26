#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;
vector<int> res;

void dfs(vector<vector<vector<int>>>& adj, int cur, ll prefA, vector<ll>& prefB) {
    auto idx = upper_bound(prefB.begin(), prefB.end(), prefA);
    if (idx != prefB.begin()) {
        --idx;
    }
    int diff = idx - prefB.begin();
    res[cur] = diff;
    for (auto& to : adj[cur]) {
        prefA += to[1];
        prefB.push_back(prefB.back() + to[2]);
        dfs(adj, to[0], prefA, prefB);
        prefA -= to[1];
        prefB.pop_back();
    }
}

// technically undirected but we can represent as directed graph from 1
// dfs from 1, track prefix sum for A and track a prefix sum vector for B, binary search on B to find longest valid prefix
void solution(vector<vector<vector<int>>>& adj) {
    res.clear();
    res.resize(N+1, 0);
    vector<ll> prefB = {0};
    dfs(adj, 1, 0, prefB);
    for (int i=2; i<=N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    int T, p, a, b;
    cin >> T;
    while (T--) {
        cin >> N;
        // adj stores <to, weightA, weightB>
        vector<vector<vector<int>>> adj(N+1);
        for (int j=2; j<=N; ++j) {
            cin >> p >> a >> b;
            adj[p].push_back({j, a, b});
        }
        solution(adj);
    }
    return 0;
}