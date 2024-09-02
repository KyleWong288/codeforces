#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;
string weights;
int numQ, num0, num1, numInternal;

// only goal is to count leaves and internal '?'
void dfs(vector<vector<int>>& adj, int cur, int par) {
    if (adj[cur].size() == 1 && par != -1) {
        if (weights[cur] == '?') ++numQ;
        else if (weights[cur] == '0') ++num0;
        else ++num1;
        return;
    }
    for (auto& to : adj[cur]) {
        if (to != par) dfs(adj, to, cur);
    }
    if (par != -1 && weights[cur] == '?') ++numInternal;
}

// assigning intermediate ? nodes doesn't change anything, just think about all cases of parent {0,1} and child {0,1}
// range of scores = [-1, 1], you get +1 or -1 for every switch
// thus, a leaf has a score iff it has a different value than the root
// case 1: root is well-defined, players alternate on '?' leaves
// case 2: root is '?', pick the root first to satisfy the max(cnt0, cnt1)
// case 3: root is '?', tie between cnt0, cnt1. Whoever picks a leaf/root first is at disadvantage because second player can respond
int solve(vector<vector<int>>& edges) {
    vector<vector<int>> adj(N);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    numQ = 0, num0 = 0, num1 = 0, numInternal = 0;
    dfs(adj, 0, -1);
    // case 1:
    if (weights[0] == '0') {
        return num1 + (numQ + 1) / 2;
    }
    else if (weights[0] == '1') {
        return num0 + (numQ + 1) / 2;
    }
    // case 2:
    else if (num0 != num1) {
        return max(num0, num1) + numQ / 2;
    }
    // case 3:
    else {
        if (numInternal % 2) {
            return num0 + (numQ + 1) / 2;
        }
        else {
            return num0 + numQ / 2;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<vector<int>> edges(N-1, vector<int>(2));
        for (auto& pr : edges) {
            cin >> pr[0] >> pr[1];
            pr[0]--, pr[1]--;
        }
        cin >> weights;
        res[i] = solve(edges);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}