#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <numeric>
#include <cmath>
using namespace std;
typedef long long ll;

// i have starting one positions [s1, s2 ... sn] and ending one positions [e1, e2 ... en]
// ith starting pos maps to the ith ending pos
// dp, if we have n ones, each 0 could host the 1st 1, 2nd 1 ... nth 1
int solution(vector<int>& a, int n) {
    vector<int> pos = {-1};
    int cnt0 = 0;
    int cnt1 = 0;
    for (int i=0; i<n; ++i) {
        if (a[i]) {
            pos.push_back(i);
            ++cnt1;
        }
    }
    // dp[i][j] = min cost filling the first j ones by the ith index
    vector<vector<int>> dp(n, vector<int>(cnt1+1, 1e9));
    for (int i=0; i<n; ++i) {
        dp[i][0] = 0;
    }
    for (int i=0; i<n; ++i) {
        if (a[i] == 0) {
            ++cnt0;
            for (int j=1; j<=min(cnt0,cnt1); ++j) {
                int dist = abs(i - pos[j]);
                int take = dist;
                if (i && j) take += dp[i-1][j-1];
                int prev = 1e9;
                if (i) prev = dp[i-1][j];
                dp[i][j] = min(prev, take);
            }
        }
        else {
            if (i == 0) { continue; }
            for (int j=1; j<=cnt1; ++j) {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int res = 1e9;
    for (int i=0; i<n; ++i) {
        res = min(res, dp[i][cnt1]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> a(N);
    for (auto& x : a) {
        cin >> x;
    }
    cout << solution(a, N) << endl;
    return 0;
}