#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, Q;

// imagine [a,b] = [l,r], this would just be merge intervals and store the intervals in a sorted set to answer queries
// however, we merge based on [a,b], so we have to track [l,b] when doing the merge interval algo
void solution(vector<vector<int>>& portals, vector<int>& queries) {
    vector<pair<int,int>> intervals;
    sort(portals.begin(), portals.end());
    // stores [l, b] of current merged interval
    vector<int> range = {portals[0][0], portals[0][3]};
    for (int i=1; i<N; ++i) {
        // no overlap:
        if (portals[i][0] > range[1]) {
            intervals.push_back({range[0], range[1]});
            range = {portals[i][0], portals[i][3]};
        }
        // overlap, update b:
        else {
            range[1] = max(range[1], portals[i][3]);
        }
    }
    intervals.push_back({range[0], range[1]});
    // answer queries:
    for (auto& q : queries) {
        pair<int,int> target = {q,q};
        auto it = lower_bound(intervals.begin(), intervals.end(), target);
        if (it != intervals.end() && it->first == q) {
            cout << it->second << " ";
        }
        else if (it == intervals.begin()) {
            cout << q << " ";
        }
        else {
            it--;
            cout << max(q, it->second) << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    while (T--) {
        cin >> N;
        vector<vector<int>> v(N, vector<int>(4));
        for (auto& x : v) {
            cin >> x[0] >> x[1] >> x[2] >> x[3];
        }
        cin >> Q;
        vector<int> q(Q);
        for (auto& x : q) {
            cin >> x;
        }
        solution(v, q);
    }
    return 0;
}