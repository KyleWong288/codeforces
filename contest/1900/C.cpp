#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// returns min # of changes needed in subtree starting at cur
int dfs(vector<vector<int>>& adj, string& s, int cur) {
    if (!adj[cur][0] && !adj[cur][1]) {
        return 0;
    }
    int l = adj[cur][0];
    int r = adj[cur][1];
    int changesL = 1e8;
    int changesR = 1e8;
    if (l) {
        changesL = dfs(adj, s, l);
    }
    if (r) {
        changesR = dfs(adj, s, r);
    }
    if (s[cur] == 'U') {
        ++changesL;
        ++changesR;
    }
    else if (s[cur] == 'L') {
        ++changesR;
    }
    else {
        ++changesL;
    }
    int res = min(changesL, changesR);
    return res;
}

// bottom up dp, dp[i] = min changes in subtree of i to reach a leaf
int solution(vector<vector<int>>& adj, string& s) {
    int res = dfs(adj, s, 1);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> s;
        s = "#" + s;
        vector<vector<int>> adj(N+1, vector<int>(2));
        for (int v=1; v<=N; ++v) {
            cin >> adj[v][0];
            cin >> adj[v][1];
        }
        res[i] = solution(adj, s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}