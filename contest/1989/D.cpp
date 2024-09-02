#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// solve for each ingot independently
// equivalent problem: after t exchanges, maximize the amount of remaining ingots. if we do this, we get max operations
// compute this in reverse: greedily pick min delta and spam it until a[i] is we can afford a better delta, then move to next delta, etc
// the seqeuence of smaller c[j] works as the prefix of the sequence of larger c[j] -> sort and reuse subproblems to count faster
int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    vector<int> b(N);
    vector<int> c(M);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    for (auto& x : c) cin >> x;
    sort(c.begin(), c.end());
    // stores <cost of a, delta of a, cost of b>
    vector<vector<int>> temp(N);
    for (int i=0; i<N; ++i) {
        temp[i] = {a[i], a[i] - b[i], b[i]};
    }
    sort(temp.begin(), temp.end());
    // reduce to only usable ones
    vector<vector<int>> trades;
    trades.push_back(temp[0]);
    for (int i=1; i<N; ++i) {
        if (temp[i][0] > trades.back()[0] && temp[i][1] < trades.back()[1]) {
            trades.push_back(temp[i]);
        }
    }
    // iterate merge sorty
    ll res = 0, cur = trades[0][0], used = 1;
    int t = 0, i = 0;
    while (i < M && c[i] < trades[0][0]) ++i;
    while (i < M) {
        cout << "ON " << i << ' ' << t << " with cur: " << cur << endl;
        if (t+1 < trades.size()) {
            if (c[i] <= trades[t+1][0]) { // skip to the largest value <= c[i]
                ll spam = (c[i++] - cur) / trades[t][1];
                cout << "advancing c[i]: " << spam << endl;
                cur += spam * trades[t][1];
                used += spam;
                res += used * 2;
            }
            else { // skip to the smallest value >= next a[i]
                ll spam = (trades[t+1][0] - cur + trades[t][1] - 1) / trades[t][1];
                cout << "advancing t[i]: " << spam << endl;
                cur += spam * trades[t++][1];
                used += spam;
            }
        }
        else {
            ll spam = (c[i++] - cur) / trades[t][1];
            cout << "autoing c[i]: " << spam << endl;
            cur += spam * trades[t][1];
            used += spam;
            res += used * 2;
        }
    }
    cout << res << endl;
    return 0;
}