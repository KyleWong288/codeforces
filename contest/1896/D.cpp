#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

// 0 indexed segment tree for range sum query
vector<ll> segtree;

// params: input array v, index in segtree, left & right bound of tree segment 
void build(vector<ll>& v, int i, int tl, int tr) {
    if (tl == tr) {
        segtree[i] = v[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build(v, 2*i+1, tl, tm);
        build(v, 2*i+2, tm+1, tr);
        segtree[i] = segtree[2*i+1] + segtree[2*i+2];
    }
}

// params: index in segtree, left & right bound of tree segment, position and its new value
void update(int i, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        segtree[i] = val;
    }
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(2*i+1, tl, tm, pos, val);
        }
        else {
            update(2*i+2, tm+1, tr, pos, val);
        }
        segtree[i] = segtree[2*i+1] + segtree[2*i+2];
    }
}

// params: index in segtree, left & right bound of tree segment, inclusive left & right bound of range query
int querySum(int i, int tl, int tr, int ql, int qr) {
    if (tr < ql || tl > qr) { // no overlap
        return 0;
    }
    if (ql <= tl && tr <= qr) { // full overlap
        return segtree[i];
    }
    else {
        int tm = (tl + tr) / 2;
        ll sumL = querySum(2*i+1, tl, tm, ql, qr);
        ll sumR = querySum(2*i+2, tm+1, tr, ql, qr);
        return sumL + sumR;
    }
}

// say index i is a 1, and the suffix sum from [i, n-1] = s: we can make any sum from 1 to s
// thus, the first 1 (pivot) has the most versatility and our array is like [2 ... 2, 1, anything]
// query: s <= suffix sum or s has same parity as suffix sum and s <= sum of whole array
// update case 1: 2 before the pivot or 1 on the pivot -> no change
// update case 2: after the pivot -> update the suffix sum
// update case 3: 1 before the pivot -> move the pivot, update the suffix sum
// update case 4: 2 on the pivot -> find the next 1, update the suffix sum
// generalizing cases: update the value, update ordered set of 1s, update suffix sum and total sum
// the above is equivalent in the reverse direction as well!! (do the same for last occurence of 1 and prefix sum)
void solution(vector<ll>& a, vector<vector<int>>& queries, int n, int q) {
    vector<bool> res;
    // construct segtree for updates:
    vector<ll> tree(4*n, 0);
    segtree = tree;
    build(a, 0, 0, n-1);
    // stores indices of 1s in sorted order
    set<int> pq;
    for (int i=0; i<n; ++i) {
        if (a[i] == 1) {
            pq.insert(i);
        }
    }
    int pivotL = n+1;
    if (pq.size()) { pivotL = *pq.begin(); }
    int pivotR = -1;
    if (pq.size()) { pivotR = *pq.rbegin(); }
    int total = querySum(0, 0, n-1, 0, n-1);
    int suff = querySum(0, 0, n-1, pivotL, n-1);
    int pref = querySum(0, 0, n-1, 0, pivotR);
    for (auto& query : queries) {
        if (query[0] == 1) {
            int s = query[1];
            if (s <= suff || ((s % 2 == suff % 2) && (s <= total))) {
                res.push_back(1);
            }
            else if (s <= pref || ((s % 2 == pref % 2) && (s <= total))) {
                res.push_back(1);
            }
            else {
                res.push_back(0);
            }
        }
        else {
            int i = query[1] - 1;
            int v = query[2];
            // update a:
            int old = a[i];
            if (old == 1 && v == 2) {
                pq.erase(i);
                a[i] = 2;
            }
            if (old == 2 && v == 1) {
                pq.insert(i);
                a[i] = 1;
            }
            // update sums:
            update(0, 0, n-1, i, v);
            if (pq.size()) {
                pivotL = *pq.begin();
                pivotR = *pq.rbegin();
            }
            else {
                pivotL = n+1;
                pivotR = -1;
            }
            suff = querySum(0, 0, n-1, pivotL, n-1);
            pref = querySum(0, 0, n-1, 0, pivotR);
            total = querySum(0, 0, n-1, 0, n-1);
        }
    }
    for (auto r : res) {
        if (r) {
            cout << "YES" << endl;
        }
        else { 
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, N, Q, op, i, j;
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        vector<vector<int>> queries(Q);
        for (int q=0; q<Q; ++q) {
            cin >> op;
            if (op == 1) {
                cin >> i;
                queries[q] = {op, i};
            }
            else {
                cin >> i >> j;
                queries[q] = {op, i, j};
            }
        }
        solution(a, queries, N, Q);
    }
    return 0;
}
