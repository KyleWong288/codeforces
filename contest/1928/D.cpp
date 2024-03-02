#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <numeric>
using namespace std;
typedef long long ll;

ll N, B, X;

// (# of pairs) * B - (squads - 1) * X
// distribution looks like: [ceil(squads/cnt) ...] [floor(squads/cnt) ...]
// we have (cnt % squads) of the first, and (remaining) of the second
ll getScore(vector<ll>& c, ll squads) {
    // count pairs:
    ll pairs = 0;
    for (auto& cnt : c) {
        ll useCeil =  cnt % squads;
        ll useFloor = squads - useCeil;
        ll ceil = (cnt + squads - 1) / squads;
        ll floor = cnt / squads;
        ll remain = cnt;
        while (useCeil--) {
            remain -= ceil;
            pairs += remain * ceil;
        }
        if (remain == 0) continue;
        while (useFloor--) {
            remain -= floor;
            pairs += remain * floor;
        }
    }
    ll res = (pairs * B) - (squads-1) * X;
    return res;
}

// O(N) count # of pairs for 1 type: (cnt[s1] * cnt[rest]) + (cnt[s2] * cnt[rest]) + ..., where rest subtracts out the current cnt
// its actually O(sum(cnts)) to count # of pairs of all types, since we have at most sum(cnts) terms
// each extra squad subtracts x, but its also better to stretch as far as possible (simple proof by contradiction)
// how to distribute cnt over k squads? make as equal as possible (cnt / k), extension of max prod fixed sum
// bs on # of squads, should have concavity
ll solve(vector<ll>& c) {
    ll res = -2e18;
    int maxSquads = accumulate(c.begin(), c.end(), 0);
    int l = 1;
    int r = maxSquads;
    while (l <= r) {
        int m = (l + r) / 2;
        ll scoreM = getScore(c, m);
        ll scoreL = -2e18;
        if (m-1 >= 1) scoreL = getScore(c, m-1);
        ll scoreR = -2e18;
        if (m+1 <= maxSquads) scoreR = getScore(c, m+1);
        res = max(max(res, scoreM), max(scoreL, scoreR));
        if (scoreL <= scoreM && scoreM <= scoreR) {
            l = m+1;
        }
        else {
            r = m-1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> B >> X;
        vector<ll> c(N);
        for (auto& x : c) {
            cin >> x;
        }
        res[i] = solve(c);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}