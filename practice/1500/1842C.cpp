#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

// dp, match with the best parent
// the best parent leaves the least balls by a certain pos, aka the min diff between (pos - dp[pos])
int solution(vector<int>& v) {
    // dp[i] = max # of balls removed in v[0:i]
    vector<int> dp(N+1, 0);
    // stores <index of parent, diff>
    vector<pair<int,int>> par(N+1, {-1, -1});
    for (int i=1; i<=N; ++i) {
        int n = v[i];
        dp[i] = dp[i-1];
        if (par[n].first == -1) { // first occurence
            par[n].first = i;
            par[n].second = (i-1) - dp[i-1];
        }
        else { // match with best par
            int parI = par[n].first;
            int parDiff = par[n].second;
            dp[i] = max(dp[i], dp[parI-1] + (i - parI + 1));
            if (parDiff > (i-1) - dp[i-1]) { // update best par
                par[n].first = i;
                par[n].second = (i-1) - dp[i-1];
            }
        }
    }
    return dp[N];
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> v(N+1);
        for (int j=1; j<=N; ++j) {
            cin >> v[j];
        }
        res[i] = solution(v);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}