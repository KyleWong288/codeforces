#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;
vector<vector<ll>> dp;

ll dfs(vector<ll>& s, int l, int r) {
    // base case:
    if (l == r) {
        dp[l][l] = 0;
        return 0;
    }
    // cache case:
    if (dp[l][r] != 1e18) {
        return dp[l][r];
    }
    // regular case:
    ll resL = s[r] - s[l] + dfs(s, l+1, r);
    ll resR = s[r] - s[l] + dfs(s, l, r-1);
    dp[l][r] = min(resL, resR);
    return dp[l][r];
}

// generally we want to use extrema last, get in sorted order and pick like stone game dp
// we need to know score, as well as min & max per range (these are just the neighbors to the l & r due to sorted order)
void solution(vector<ll>& s) {
    // dp[i][j] = min cost to use runners in s[i:j]
    dp.resize(N, vector<ll>(N, 1e18));
    sort(s.begin(), s.end());
    ll res = dfs(s, 0, N-1);
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    vector<ll> s(N);
    for (auto& x : s) {
        cin >> x;
    }
    solution(s);
    return 0;
}