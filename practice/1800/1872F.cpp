#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

int N;

// returns animal id with smallest c[i]
int dfs(vector<int>& a, vector<int>& c, vector<bool>& vis, int cur) {
    if (vis[cur]) {
        return cur;
    }
    vis[cur] = 1;
    int id = dfs(a, c, vis, a[cur]);
    if (c[id] < c[cur]) {
        return id;
    }
    else {
        return cur;
    }
}

// if we had no cycles this would be basic top sort
// to handle cycles: take smallest c[i] in cycle last, rest of cycle gets 2x
// each node can be part of at most 1 cycle since they only have one out edge, so cycles are independent
void solution(vector<int>& a, vector<int>& c) {
    vector<int> res;
    // top sort until cycles are left:
    vector<int> indeg(N+1, 0);
    for (auto& x : a) {
        indeg[x]++;
    }
    vector<bool> vis(N+1, 0);
    queue<int> q;
    for (int i=1; i<=N; ++i) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        vis[cur] = 1;
        int to = a[cur];
        indeg[to]--;
        if (indeg[to] == 0) {
            q.push(to);
        }
        res.push_back(cur);
    }
    // isolate cycles and take their smallest c[i]:
    for (int i=1; i<=N; ++i) {
        if (!vis[i]) {
            int idEnd = dfs(a, c, vis, i);
            int idStart = a[idEnd];
            indeg[idStart] = -1;
            q.push(idStart);
        }
    }
    // top sort remaining:
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int to = a[cur];
        indeg[to]--;
        if (indeg[to] == 0) {
            q.push(to);
        }
        res.push_back(cur);
    }
    for (auto& r : res) {
        cout << r << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> a(N+1);
        vector<int> c(N+1);
        for (int i=1; i<=N; ++i) {
            cin >> a[i];
        }
        for (int i=1; i<=N; ++i) {
            cin >> c[i];
        }
        solution(a, c);
    }
    return 0;
}