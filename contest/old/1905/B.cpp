#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// number of leaves?
// leaf to leaf path deletes the most vertices, and each time we lose 2 leaves
// count leaves by indegree
int solution(vector<vector<int>>& adj) {
    int cnt = 0;
    for (int i=1; i<=N; ++i) {
        if (adj[i].size() == 1) {
            ++cnt;
        }
    }
    int res = (cnt + 1) / 2;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int u, v;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<vector<int>> adj(N+1);
        for (int j=0; j<N-1; ++j) {
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