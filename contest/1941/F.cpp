#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M, K;

// find max original diff D, if more than 1 occurence, we can't change our imbalance
// try to split D: D is between [low, high], see if we can get some m + f in between
// for each m, theres a bestF that lands in the middle of [low, high]
// bs, try to get as close to bestF as possible
ll solve(vector<ll>& a, vector<ll>& m, vector<ll>& f) {
    sort(a.begin(), a.end());
    sort(m.begin(), m.end());
    sort(f.begin(), f.end());
    vector<ll> diffs;
    for (int i=1; i<N; ++i) {
        diffs.push_back(a[i] - a[i-1]);
    }
    sort(diffs.rbegin(), diffs.rend());
    if (diffs.size() > 1 && diffs[0] == diffs[1]) return diffs[0];
    // get low and high:
    ll low, mid, high;
    for (int i=1; i<N; ++i) {
        if (a[i] - a[i-1] == diffs[0]) {
            low = a[i-1];
            high = a[i];
            mid = (low + high) / 2;
            break;
        }
    }
    ll res = diffs[0];
    for (auto& x : m) {
        ll bestF = mid - x;
        int idx = lower_bound(f.begin(), f.end(), bestF) - f.begin();
        if (idx == K) idx--;
        // compute right:
        ll newScore = x + f[idx];
        ll diffL = newScore - low;
        ll diffR = high - newScore;
        if (diffL < diffs[0] && diffR < diffs[0]) {
            if (diffs.size() > 1 && diffL < diffs[1] && diffR < diffs[1]) {
                return diffs[1];
            }
            res = min(res, max(diffL, diffR));
        }
        // compute left:
        if (idx > 0) {
            idx--;
            newScore = x + f[idx];
            diffL = newScore - low;
            diffR = high - newScore;
            if (diffL < diffs[0] && diffR < diffs[0]) {
                if (diffs.size() > 1 && diffL < diffs[1] && diffR < diffs[1]) {
                    return diffs[1];
                }
                res = min(res, max(diffL, diffR));
            }
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
        cin >> N >> M >> K;
        vector<ll> a(N);
        vector<ll> models(M);
        vector<ll> funcs(K);
        for (auto& x : a) {
            cin >> x;
        }
        for (auto& x : models) {
            cin >> x;
        }
        for (auto& x : funcs) {
            cin >> x;
        }
        res[i] = solve(a, models, funcs);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}