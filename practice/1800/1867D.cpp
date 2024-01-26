#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

int n, k;

// we can fix the first element of each subsequence by having l = [i, a[i], ...]
// if we do this, we need to finish properly at the end (the last k needs to be a perfect match)
// creates a directed graph where edges are i -> a[i]
// all cycles need to have length k
// edge case for k = 1, since we can only form edges where i == a[i]
int solve(vector<int>& a) {
    if (k == 1) {
        for (int i=1; i<=n; ++i) {
            if (i != a[i]) {
                return 0;
            }
        }
        return 1;
    }
    vector<int> to(n+1);
    for (int i=1; i<=n; ++i) {
        to[i] = a[i];
    }
    // tracks if visited, also tracks position on the cycle
    vector<bool> vis(n+1, 0);
    for (int i=1; i<=n; ++i) {
        int cur = i;
        int len = 1;
        map<int,int> path;
        while (!vis[cur]) {
            vis[cur] = 1;
            path[cur] = len++;
            cur = to[cur];
        }
        // cycle detect
        if (path.find(cur) != path.end()) {
            int diff = len - path[cur];
            if (diff != k) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> k;
        vector<int> a(n+1);
        for (int j=1; j<=n; ++j) {
            cin >> a[j];
        }
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << (r ? "YES\n" : "NO\n");
    }
    return 0;
}