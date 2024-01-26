#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
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
        segtree[i] = gcd(segtree[2*i+1], segtree[2*i+2]);
    }
}

// params: index in segtree, left & right bound of tree segment, inclusive left & right bound of range query
ll query(int i, int tl, int tr, int ql, int qr) {
    if (tl > qr || tr < ql) { // no overlap
        return 0;
    }
    if (ql <= tl && tr <= qr) { // full overlap
        return segtree[i];
    }
    int tm = (tl + tr) / 2;
    ll gl = query(2*i+1, tl, tm, ql, qr);
    ll gr = query(2*i+2, tm+1, tr, ql, qr);
    return gcd(gl, gr);
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
        segtree[i] = gcd(segtree[2*i+1], segtree[2*i+2]);
    }
}

// example usage
int main() {
    vector<ll> v = {3, 1, 4, 1, 5, 9, 2, 6};
    int N = v.size();
    segtree.resize(4*N);
    build(v, 0, 0, N-1);
    cout << query(0, 0, N-1, 0, 7) << endl;
    cout << query(0, 0, N-1, 3, 7) << endl;
    cout << query(0, 0, N-1, 0, 0) << endl;
    cout << query(0, 0, N-1, 1, 4) << endl;
    update(0, 0, N-1, 3, 10);
    cout << query(0, 0, N-1, 0, 7) << endl;
    cout << query(0, 0, N-1, 3, 7) << endl;
    cout << query(0, 0, N-1, 0, 0) << endl;
    cout << query(0, 0, N-1, 1, 4) << endl;
    return 0;
}