#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

int N, M;

// dp[i] = max # of cats we can feed by using any indices from [0, i]
// to take at i, lookup the left most point L in the current set of intervals, then add dp[L-1]
// need to maintain current set of intervals and query left most point -> use set of pairs
// important to process by batch: (add all lefts, freeze and get left most, remove all rights), removing all rights may change the left most
int solve(vector<vector<int>>& intervals) {
    // stores <time, left/right, id>, process left events (-1) before right events (+1)
    vector<vector<int>> events(2*M);
    for (int i=0; i<M; ++i) {
        events[2*i] = {intervals[i][0], -1, i};
        events[2*i+1] = {intervals[i][1], 1, i};
    }
    sort(events.begin(), events.end());
    int e = 0;
    // dp[i] = max # of cats we can feed by using any indices from [0, i]
    vector<int> dp(N+1, 0);
    // stores <left, id>
    set<pair<int,int>> ints;
    for (int i=1; i<=N; ++i) {
        // process by batch: add all lefts then remove all rights
        while (e < 2*M && events[e][0] == i && events[e][1] == -1) {
            int id = events[e][2];
            ints.insert({i, id});
            ++e;
        }
        int left = 1;
        if (ints.size()) left = ints.begin()->first;
        int total = ints.size();
        while (e < 2*M && events[e][0] == i && events[e][1] == 1) {
            int id = events[e][2];
            ints.erase({intervals[id][0], id});
            ++e;
        }
        dp[i] = max(dp[left-1] + total, dp[i-1]);
    }
    return dp[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<vector<int>> intervals(M, vector<int>(2));
        for (auto& pr : intervals) {
            cin >> pr[0] >> pr[1];
        }
        res[i] = solve(intervals);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}