#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int W, F, N, wCap, fCap, res;

// top down, honestly its not even dp, we just don't want to revisit same state
void dfs(vector<vector<bool>>& vis, vector<int>& pref, vector<int>& s, int i, int j) {
    // base case:
    if (i >= N) {
        int wUsed = j;
        int fUsed = pref.back() - j;
        int tW = (wUsed + W - 1) / W;
        int tF = (fUsed + F - 1) / F;
        res = min(res, max(tW, tF));
        return;
    }
    if (vis[i][j]) {
        return;
    }
    vis[i][j] = 1;
    // try taking index i as water:
    dfs(vis, pref, s, i+1, j + s[i]);
    // try taking index i as fire:
    dfs(vis, pref, s, i+1, j);
}

// Naive: dp[i][j][k] = min time to reach monster i with j water used and k fire used
// Better: drop the 3rd dimension, we don't need to track fire used, its a function of i and j
// Better: if we go top down, we only care about times at index i, so dp can just be vis since there is no subproblem dependency
// fire used = prefix sum of strengths - water used -> pref[i] - j
// computing min T: T * W >= wUsed and T * F >= fUsed -> T = max(wUsed / W, fUsed / F)
int solution(vector<int>& s) {
    res = 1e9;
    vector<int> pref(N);
    pref[0] = s[0];
    for (int i=1; i<N; ++i) {
        pref[i] = s[i] + pref[i-1];
    }
    vector<vector<bool>> vis(N+1, vector<bool>(pref.back()+1, 0));
    dfs(vis, pref, s, 0, 0);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> W >> F >> N;
        vector<int> s(N);
        for (auto& x : s) {
            cin >> x;
        }
        res[i] = solution(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}