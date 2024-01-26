#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N, M, Q;

// 0 indexed segtree
vector<int> segtree;

// initializes segtree with max
void build(vector<int>& a, int i, int tl, int tr) {
    if (tl == tr) {
        segtree[i] = a[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build(a, i*2+1, tl, tm);
        build(a, i*2+2, tm+1, tr);
        segtree[i] = max(segtree[i*2+1], segtree[i*2+2]);
    }
}

// top down query max in range 
int query(int i, int tl, int tr, int l, int r) {
    if (tl > r || tr < l) { // no overlap
        return 0;
    }
    if (l <= tl && tr <= r) { // total overlap
        return segtree[i];
    }
    int tm = (tl + tr) / 2;
    int maxL = query(i*2+1, tl, tm, l, r);
    int maxR = query(i*2+2, tm+1, tr, l, r);
    int res = max(maxL, maxR);
    return res;
}

// for convenience, number rows (1 - N) from top to bottom
// spam down as much as possible, spam left/right as necessary, spam up as necessary: delta row and delta col must be multiples of k
// if there exists a blockage between [start col, finish col] even if you spam down, you fail. Find blockage with segtree (find max in range)
void solution(vector<int>& a, vector<vector<int>>& queries) {
    segtree.resize(4 * M, 0);
    build(a, 0, 0, M-1);
    vector<bool> res(Q);
    int sr, sc, fr, fc, k;
    for (int i=0; i<Q; ++i) {
        // have rows be 1 indexed, have cols be 0 indexed for seg tree
        sr = queries[i][0], sc = queries[i][1]-1, fr = queries[i][2], fc = queries[i][3]-1, k = queries[i][4];
        int delR = abs(sr - fr);
        int delC = abs(sc - fc);
        if (delR % k || delC % k) {
            res[i] = 0;
            continue;
        }
        //  get the furthest down you can spam
        int diff = N - sr;
        int spam = diff / k;
        int d = sr + spam * k;
        // check if larger value exists between sc and fc
        if (sc > fc) {
            swap(sc, fc);
        }
        int rmq = query(0, 0, M-1, sc, fc);
        rmq >= d ? res[i] = 0 : res[i] = 1;
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
    cin >> N >> M;
    vector<int> a(M);
    for (auto& x : a) {
        cin >> x;
    }
    cin >> Q;
    // queries store <sr, sc, fr, fc, k>
    vector<vector<int>> queries(Q, vector<int>(5));
    for (auto& q : queries) {
        cin >> q[0] >> q[1] >> q[2] >> q[3] >> q[4];
    }
    solution(a, queries);
    return 0;
}