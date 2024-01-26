#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int Q;

// type 1: height range is in [(a-b)(n-2) + a + 1 and (a-b)(n-1) + a], track a running intersection of these intervals
// type 2: current interval is [L, R], for (a-b)*p + a >= L and (a-b)*q + a <= R, p must equal q
void solution(vector<vector<ll>>& queries) {
    vector<ll> res(Q);
    pair<ll,ll> interval = {0, 2e18};
    ll a, b, n;
    for (int i=0; i<Q; ++i) {
        if (queries[i][0] == 1) {
            a = queries[i][1], b = queries[i][2], n = queries[i][3];
            ll l = (a-b) * (n-2) + a + 1;
            ll r = (a-b) * (n-1) + a;
            // edge case where n = 1
            if (n == 1) {
                l = 1;
                r = a;
            }
            if (r < interval.first || l > interval.second) { // no overlap
                res[i] = 0;
            }
            else { // yes overlap and intersect
                interval.first = max(l, interval.first);
                interval.second = min(r, interval.second);
                res[i] = 1;
            }
        }
        else {
            a = queries[i][1], b = queries[i][2];
            // make sure to ceiling p and q
            ll p = (interval.first - a + (a - b - 1)) / (a - b);
            ll q = (interval.second - a + (a - b - 1)) / (a - b);
            p = max(p, 0LL) + 1;
            q = max(q, 0LL) + 1;
            if (p == q) { // can determine
                res[i] = p;
            }
            else { // can't determine
                res[i] = -1;
            }
        }
    }
    for (auto& x : res) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    ll type, a, b, n;
    while (T--) {
        cin >> Q;
        vector<vector<ll>> queries(Q);
        for (auto& q : queries) {
            cin >> type;
            if (type == 1) {
                cin >> a >> b >> n;
                q = {type, a, b, n};
            }
            else {
                cin >> a >> b;
                q = {type, a, b};
            }
        }
        solution(queries);
    }
    return 0;
}