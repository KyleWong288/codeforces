#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// right to left dp
int solution(vector<int>& v) {
    // dp[i] = min # of deletions from v[i:N-1] if we treated v[i] as a size
    vector<int> dp(N+1, 0);
    dp[N-1] = 1;
    for (int i=N-2; i>=0; --i) {
        // delete
        dp[i] = dp[i+1] + 1;
        // use as size
        if (i + v[i] < N) {
            dp[i] = min(dp[i], dp[i+v[i]+1]);
        }
    }
    return dp[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> v(N);
        for (auto& x : v) {
            cin >> x;
        }
        res[i] = solution(v);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}