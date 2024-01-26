#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

ll dfs(vector<vector<int>>& adj, vector<pair<ll,ll>>& ranges, int cur, int& res) {
    // leaf node always adds 1:
    if (adj[cur].empty()) {
        ++res;
        return ranges[cur].second;
    }
    ll sum = 0;
    for (auto& to : adj[cur]) {
        sum += dfs(adj, ranges, to, res);
    }
    // extra op and reset:
    if (sum < ranges[cur].first) {
        ++res;
        return ranges[cur].second;
    }
    // want to be as large as possible:
    else {
        return min(sum, ranges[cur].second);
    }
}

// each leaf needs one op
// everytime we have a decrease in a root->leaf path, we need an extra op
// thus we want to construct paths bottom up using the largest values possible
int solution(vector<int>& par, vector<pair<ll,ll>>& ranges, int n) {
    int res = 0;
    vector<vector<int>> adj(n+1);
    for (int i=2; i<=n; ++i) {
        adj[par[i]].push_back(i);
    }
    dfs(adj, ranges, 1, res);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, N;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> par(N+1);
        for (int j=2; j<=N; ++j) {
            cin >> par[j];
        }
        vector<pair<ll,ll>> ranges(N+1);
        for (int j=1; j<=N; ++j) {
            cin >> ranges[j].first >> ranges[j].second;
        }
        res[i] = solution(par, ranges, N);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}