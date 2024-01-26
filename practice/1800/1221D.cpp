#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// never need to add more than 2 to any index
// dp over the 3 possible values at each index
ll solution(vector<vector<ll>>& boards) {
    // dp[i] = min cost ending on index i, with using {0, 1, 2} adds on the current index
    vector<ll> dp0(N, 2e18);
    vector<ll> dp1(N, 2e18);
    vector<ll> dp2(N, 2e18);
    dp0[0] = 0;
    dp1[0] = boards[0][1];
    dp2[0] = 2 * boards[0][1];
    for (int i=1; i<N; ++i) {
        ll prev = boards[i-1][0];
        ll cur = boards[i][0];
        ll cost = boards[i][1];
        // add 0:
        if (prev != cur) dp0[i] = min(dp0[i], dp0[i-1]);
        if (prev+1 != cur) dp0[i] = min(dp0[i], dp1[i-1]);
        if (prev+2 != cur) dp0[i] = min(dp0[i], dp2[i-1]);
        // add 1:
        if (prev != cur+1) dp1[i] = min(dp1[i], dp0[i-1] + cost);
        if (prev+1 != cur+1) dp1[i] = min(dp1[i], dp1[i-1] + cost);
        if (prev+2 != cur+1) dp1[i] = min(dp1[i], dp2[i-1] + cost);
        // add 2:
        if (prev != cur+2) dp2[i] = min(dp2[i], dp0[i-1] + cost * 2);
        if (prev+1 != cur+2) dp2[i] = min(dp2[i], dp1[i-1] + cost * 2);
        if (prev+2 != cur+2) dp2[i] = min(dp2[i], dp2[i-1] + cost * 2);
    }
    ll res = min(dp0[N-1], min(dp1[N-1], dp2[N-1]));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<vector<ll>> boards(N, vector<ll>(2));
        for (auto& b : boards) {
            cin >> b[0] >> b[1];
        }
        res[i] = solution(boards);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}