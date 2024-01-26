#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// take alice and bob turn at the same time so we know the relation between chars at the same index
int dfs(vector<vector<int>>& dp, string& s, int l, int r) {
    // cache case:
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    // base case:
    if (l == r-1) { 
        if (s[l] == s[r]) {
            dp[l][r] = 0;
        }
        else {
            dp[l][r] = 1;
        }
        return dp[l][r];
    }
    int res1, res2, res3, res4;
    // case 1: A take l, B take l+1
    res1 = dfs(dp, s, l+2, r);
    if (res1 == 0 && s[l] > s[l+1]) {
        res1 = 1;
    }
    // case 2: A take l, B take r
    res2 = dfs(dp, s, l+1, r-1);
    if (res2 == 0 && s[l] > s[r]) {
        res2 = 1;
    }
    // case 3: A take r, B take l
    res3 = dfs(dp, s, l+1, r-1);
    if (res3 == 0 && s[r] > s[l]) {
        res3 = 1;
    }
    // case 4: A take r, B take r-1
    res4 = dfs(dp, s, l, r-2);
    if (res4 == 0 && s[r] > s[r-1]) {
        res4 = 1;
    }
    if ((res1 && res2) || (res3 && res4)) {
        dp[l][r] = 1;
    }
    else {
        dp[l][r] = 0;
    }
    return dp[l][r];
}

// bottom up dp like stone game but your states are {tie, winA}, lowkey bob cant win i think
int solution(string& s) {
    int N = s.size();
    // dp[i][j] = outcome on the subgame on s from [i, j]
    // 0 = tie, 1 = alice wins
    vector<vector<int>> dp(N, vector<int>(N, -1));
    int res = dfs(dp, s, 0, N-1);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> s;
        res[i] = solution(s);
    }
    for (auto& r : res) {
        if (r == 1) {
            cout << "Alice" << endl;
        }
        else {
            cout << "Draw" << endl;
        }
    }
    return 0;
}