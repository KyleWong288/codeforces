#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <numeric>
#include <cmath>
using namespace std;
typedef long long ll;

int N, K;

// start at k and find net positive endpoints moving outward
// if you can reach a net positive endpoint, you always profit to take it, so add it if possible
// if you can't reach either endpoints around you, its impossible since you've taken all profits you can
int solution(vector<ll>& a) {
    // compute profitable endpoints:
    // stores <profit, minimal required starting sum to take, new inclusive endpoint index>
    vector<vector<ll>> profits;
    for (int i=K-1; i>=0; --i) {
        ll sum = 0;
        ll mostNeg = 0;
        int j = i;
        while (j >= 0 && sum <= 0) {
            sum += a[j--];
            mostNeg = min(mostNeg, sum);
        }
        if (sum > 0) {
            profits.push_back({sum, abs(mostNeg), j+1});
        }
        i = j+1;
    }
    reverse(profits.begin(), profits.end());
    profits.push_back({a[K], 0, K});
    int pl = profits.size() - 1;
    int pr = pl + 1;
    for (int i=K+1; i<N; ++i) {
        ll sum = 0;
        ll mostNeg = 0;
        int j = i;
        while (j < N && sum <= 0) {
            sum += a[j++];
            mostNeg = min(mostNeg, sum);
        }
        if (sum > 0) {
            profits.push_back({sum, abs(mostNeg), j-1});
        }
        i = j-1;
    }
    // spread endpoints to get max profit:
    ll prof = 0;
    while (pl >= 0 || pr < profits.size()) {
        bool takeL = 0;
        bool takeR = 0;
        if (pl >= 0 && prof >= profits[pl][1]) {
            takeL = 1;
            prof += profits[pl--][0];
        }
        if (pr < profits.size() && prof >= profits[pr][1]) {
            takeR = 1;
            prof += profits[pr++][0];
        }
        if (!takeL && !takeR) {
            break;
        }
    }
    // can no longer get profit, beeline an endpoint:
    int l = profits[pl+1][2] - 1;
    int r = profits[pr-1][2] + 1;
    bool makeL = 1;
    bool makeR = 1;
    ll lossL = 0;
    for (int i=l; i>=0; --i) {
        lossL += a[i];
        if (lossL * -1 > prof) {
            makeL = 0;
        }
    }
    ll lossR = 0;
    for (int i=r; i<N; ++i) {
        lossR += a[i];
        if (lossR * -1 > prof) {
            makeR = 0;
        }
    }
    if (makeL || makeR) {
        return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
        --K;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solution(a);
    }
    for (auto& r : res) {
        if (r) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}