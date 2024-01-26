#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <numeric>
using namespace std;
typedef long long ll;

int N;
vector<ll> segtree;

// i is idx in segtree, l and r are range in a
void build(vector<ll>& a, int i, int l, int r) {
    if (l == r) {
        segtree[i] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(a, 2*i+1, l, m);
    build(a, 2*i+2, m+1, r);
    segtree[i] = gcd(segtree[2*i+1], segtree[2*i+2]);
}

// idx, tree (l,r), original bound (l,r)
ll query(int i, int tl, int tr, int l, int r) {
    if (l > tr || r < tl) { // no overlap
        return 0;
    }
    if (l <= tl && tr <= r) { // full overlap
        return segtree[i];
    }
    int tm = (tl + tr) / 2;
    ll gl = query(2*i+1, tl, tm, l, r);
    ll gr = query(2*i+2, tm+1, tr, l, r);
    return gcd(gl, gr);
}

// a[i] mod m == a[j] mod m -> (a[i] - a[j]) mod m == 0, so m divides adjacent diffs
// so create the array of diffs, find the largest subarray with a common divisor (use gcd)
// seg tree works for subarray gcd queries, slide right pointer until gcd = 1, slide left pointer until gcd > 1
// edge case: when l == r, does this mean we take the diff or not -> it can mean both, so let l == r+1 represent not taking the diff
int solve(vector<ll>& a) {
    if (N == 1) { return 1; }
    int res = 0;
    segtree.clear();
    vector<ll> diffs(N-1);
    for (int i=0; i<N-1; ++i) {
        diffs[i] = abs(a[i+1] - a[i]);
    }
    --N;
    segtree.resize(4*N);
    build(diffs, 0, 0, N-1);
    int l = 0;
    for (int r=0; r<N; ++r) {
        ll g = query(0, 0, N-1, l, r);
        while (g == 1 && l <= r) {
            ++l;
            g = query(0, 0, N-1, l, r);
        }
        res = max(res, r - l + 1);
    }
    return res + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}