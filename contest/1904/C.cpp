#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

ll N, K;

// if you have >=3 ops: you just get 0 (pick any two indices, get their diff twice, then diff of diffs = 0)
// if you have 2 ops: brute force over diff d from all pairs, use bs to compare d with closest smaller & larger vals
// if you have 1 op: min between smallest value and smallest diff
ll solution(vector<ll>& a) {
    sort(a.begin(), a.end());
    if (K >= 3) {
        return 0;
    }
    else if (K == 2) {
        ll res = 2e18;
        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                ll d = abs(a[i] - a[j]);
                res = min(res, d);
                int idxH = (upper_bound(a.begin(), a.end(), d) - a.begin());
                int idxL = idxH - 1;
                if (idxH < N) {
                    res = min(res, a[idxH] - d);
                }
                if (idxL >= 0) {
                    res = min(res, d - a[idxL]);
                }
            }
        }
        return min(a[0], res);
    }
    else if (K == 1) {
        ll res = 2e18;
        for (int i=1; i<N; ++i) {
            res = min(res, a[i] - a[i-1]);
        }
        return min(a[0], res);
    }
    else {
        return a[0];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solution(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}