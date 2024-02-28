#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, Q;

// good strat: if c[i] is not 1, place 1. if c[i] is 1, place some diff > 1
// sus ranges: sum of range < (# of non 1s * 1) + (# of 1s * 2)
// also queries with range 1 obv dont work
void solve(vector<int>& a, vector<vector<int>>& queries) {
    vector<ll> res(Q);
    // ps[i] = sum of values from [0, i-1]
    vector<ll> ps(N+1);
    // psNon[i] = # of non 1s from [0, i-1]
    vector<ll> psNon(N+1);
    // psOne[i] = # of 1s from [0, i-1]
    vector<ll> psOne(N+1);
    for (int i=0; i<N; ++i) {
        ps[i+1] = ps[i] + a[i];
        if (a[i] == 1) {
            psNon[i+1] = psNon[i];
            psOne[i+1] = psOne[i] + 1;
        }
        else {
            psNon[i+1] = psNon[i] + 1;
            psOne[i+1] = psOne[i];
        }
    }
    for (int q=0; q<Q; ++q) {
        int l = queries[q][0] - 1;
        int r = queries[q][1] - 1;
        ll sum = ps[r+1] - ps[l];
        ll numNon = psNon[r+1] - psNon[l];
        ll numOne = psOne[r+1] - psOne[l];
        if (sum < numNon + 2 * numOne || l == r) {
            res[q] = 0;
        }
        else {
            res[q] = 1;
        }
    }
    for (auto& r : res) {
        cout << (r ? "YES\n" : "NO\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        vector<int> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        vector<vector<int>> queries(Q, vector<int>(2));
        for (auto& q : queries) {
            cin >> q[0] >> q[1];
        }
        solve(a, queries);
    }
    return 0;
}