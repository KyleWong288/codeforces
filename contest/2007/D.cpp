#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;
string weights;
int numVolatile;
int numStable;

// tracks previous value and current balance between 10 and 01
void dfs(vector<vector<int>>& adj, int cur, int par, char prevChar, int bal) {
    if (par >= 0) {
        if (prevChar == '1' && weights[cur] == '0') ++bal;
        if (prevChar == '0' && weights[cur] == '1') --bal;
    }
    // leaf node base case, check if its volatile:
    if (par >= 0 && adj[cur].size() == 1) {
        if (weights[cur] == '?') {
            if (bal == 1 && prevChar == '0') ++numVolatile;
            else if (bal == -1 && prevChar == '1') ++numVolatile;
            else if (bal == 0) ++numVolatile; 
            else ++numStable;
        }
        else {
            numStable += (bal != 0);
        }
        return;
    }
    // regular case:
    char myChar = weights[cur];
    if (myChar == '?') myChar = prevChar;
    for (auto& to : adj[cur]) {
        if (to == par) continue;
        dfs(adj, to, cur, myChar, bal);
    }
}

// assigning intermediate ? nodes doesn't change anything, just think about all cases of parent {0,1} and child {0,1}
// ? at leaf or root: impacts at most 1 path
// choosing 0 or 1 based on top down dfs, then find the set of volatile leaves, p1 and p2 compete in this set
// ? at root: impacts at least 1 path, not sure between 0 and 1, try both?
// how to choose root????
int solve(vector<vector<int>>& edges, bool startP1) {
    vector<vector<int>> adj(N);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    numVolatile = 0;
    numStable = 0;
    dfs(adj, 0, -1, 'X', 0);
    if (startP1) {
        return numStable + (numVolatile + 1) / 2;
    }
    else {
        return numStable + numVolatile / 2;
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
        // try both if root is '?'
        if (weights[0] == '?') {
            weights[0] = '1';
            int r1 = solve(edges, 0);
            weights[0] = '0';
            int r2 = solve(edges, 0);
            res[i] = max(r1, r2);
        }
        else {
            res[i] = solve(edges, 1);
        }
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}