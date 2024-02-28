#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, Q;

// prefix sum the amount of sections
// binary search right end until sections used <= u, either use that guy or a neighbor
void solve(vector<ll>& a, vector<vector<int>>& queries) {
    vector<ll> res(Q);
    vector<ll> ps(N+1);
    for (int i=0; i<N; ++i) {
        ps[i+1] = ps[i] + a[i];
    }
    for (int q=0; q<Q; ++q) {
        int start = queries[q][0] - 1;
        ll u = queries[q][1];
        int l = start;
        int r = N-1;
        while (l <= r) {
            int m = (l + r) / 2;
            ll sum = ps[m+1] - ps[start];
            if (sum <= u) {
                l = m+1;
            }
            else {
                r = m-1;
            }
        }
        // r is the maximum sum under u
        r = max(r, start);
        ll used = ps[r+1] - ps[start];
        ll endingVal = u - used + 1;
        ll curScore = (u + endingVal) * used / 2;
        ll nextScore = -1e18;
        if (r < N-1) {
            used = ps[r+2] - ps[start];
            endingVal = u - used + 1;
            nextScore = (u + endingVal) * used / 2;
        }
        res[q] = (nextScore > curScore ? r+1 : r);
    }
    for (auto& x : res) {
        cout << x+1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        cin >> Q;
        vector<vector<int>> queries(Q, vector<int>(2));
        for (auto& q : queries) {
            cin >> q[0] >> q[1];
        }
        solve(a, queries);
    }
    return 0;
}