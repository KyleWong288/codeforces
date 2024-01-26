#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

int N, Q;

// we can unravel op 2, but this becomes O(# of op 2) for each query
// op 2 at least doubles the array size, we only care about the first 60 or so of them
// need to differentiate if an index is real (added by op 1) or spam (added by op 2)
// we can unravel op 2 by knowing the the size of the array before spamming, the parent pointer is just modulo array size
void solution(vector<vector<ll>>& ops, vector<ll>& queries) {
    // stores <idx, real value>
    map<ll,ll> reals;
    // stores lengths before each spam
    vector<ll> lens = {0};
    ll len = 0;
    for (auto& op : ops) {
        if (op[0] == 1) {
            reals[len++] = op[1];
        }
        else {
            // overflows 1e18
            if (len >= (ll)2e18 / (op[1] + 1)) {
                lens.push_back(len);
                break;
            }
            else {
                lens.push_back(len);
                len *= (op[1] + 1);
            }
        }
    }
    lens.push_back(2e18);
    vector<ll> res(Q);
    for (int q=0; q<Q; ++q) {
        ll idx = queries[q];
        ll lenIdx = upper_bound(lens.begin(), lens.end(), idx) - lens.begin();
        --lenIdx;
        while (reals.find(idx) == reals.end()) {
            idx = idx % (lens[lenIdx]);
            --lenIdx;
        }
        res[q] = reals[idx];
    }
    for (auto& r : res) {
        cout << r << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        vector<vector<ll>> ops(N, vector<ll>(2));
        for (auto& op : ops) {
            cin >> op[0] >> op[1];
        }
        vector<ll> queries(Q);
        for (auto& x : queries) {
            cin >> x;
            --x;
        }
        solution(ops, queries);
    }
    return 0;
}