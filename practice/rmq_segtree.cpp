#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// 0 indexed segment tree for range max query
vector<int> segtree;

// params: input array v, index in segtree, left & right bound of tree segment
void build(vector<int>& v, int i, int tl, int tr) {
    if (tl == tr) {
        segtree[i] = v[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build(v, 2*i+1, tl, tm);
        build(v, 2*i+2, tm+1, tr);
        segtree[i] = max(segtree[2*i+1], segtree[2*i+2]);
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
        segtree[i] = max(segtree[2*i+1], segtree[2*i+2]);
    }
}

// params: index in segtree, left & right bound of tree segment, inclusive left & right bound of range query
int query(int i, int tl, int tr, int l, int r) {
    if (tr < l || tl > r) { // no overlap
        return INT_MIN;
    }
    if (l <= tl && r >= tr) { // full overlap
        return segtree[i];
    }
    int tm = (tl + tr) / 2;
    return max(query(2*i+1, tl, tm, l, r), query(2*i+2, tm+1, tr, l, r));
}

// example usage
int main() {
    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
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