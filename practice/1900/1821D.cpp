#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

int N, K;

// only way we can optimize is to decrease the # of press/release actions
// longer strips better than shorter strips, use pq to track and backtrack on shorter strips
// always paint exactly K cells and end on a painted cell: ops = pos - (excess black) + (2 * ranges used)
ll solution(vector<pair<ll,ll>>& ranges) {
    ll res = 1e18;
    ll pos = 0;
    ll black = 0;
    priority_queue<ll, vector<ll>, greater<>> pq;
    for (auto& range : ranges) {
        pos = range.second;
        ll len = range.second - range.first + 1;
        black += len;
        pq.push(len);
        while (black >= K) {
            ll ops = pos - (black - K) + (2 * pq.size());
            res = min(res, ops);
            black -= pq.top();
            pq.pop();
        }
    }
    if (res == 1e18) {
        return -1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
        vector<pair<ll,ll>> ranges(N);
        for (int i=0; i<N; ++i) {
            cin >> ranges[i].first;
        }
        for (int i=0; i<N; ++i) {
            cin >> ranges[i].second;
        }
        res[i] = solution(ranges);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}