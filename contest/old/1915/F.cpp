#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// 0 indexed segment tree for range max query
vector<ll> segtree;

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
ll query(int i, int tl, int tr, int ql, int qr) {
    if (tr < ql || tl > qr) { // no overlap
        return 0;
    }
    if (ql <= tl && tr <= qr) { // full overlap
        return segtree[i];
    }
    else {
        int tm = (tl + tr) / 2;
        ll sumL = query(2*i+1, tl, tm, ql, qr);
        ll sumR = query(2*i+2, tm+1, tr, ql, qr);
        return sumL + sumR;
    }
}

// if 1 greets 2, this can only happen if a1 < a2 and b1 > b2
// interval decomp and maintain segtree of 0s and 1s
// scan a[i]: set segtree at id to 1
// scan b[i]: set segtree at id to 0, then count # of set bits to the left of id
ll solution(vector<vector<int>>& ranges) {
    segtree.clear();
    segtree.resize(4*N, 0);
    sort(ranges.begin(), ranges.end());
    // events stores <time, +1/-1, id in [0,N-1]>
    vector<vector<int>> events;
    for (int i=0; i<N; ++i) {
        events.push_back({ranges[i][0], 1, i});
        events.push_back({ranges[i][1], -1, i});
    }
    sort(events.begin(), events.end());
    ll res = 0;
    for (auto& e : events) {
        int id = e[2];
        if (e[1] == 1) {
            update(0, 0, N-1, id, 1);
        }
        else {
            update(0, 0, N-1, id, 0);
            res += query(0, 0, N-1, 0, id-1);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        // stores <time, +1 for a, -1 for b>
        vector<vector<int>> events(N, vector<int>(2));
        for (auto& e : events) {
            cin >> e[0] >> e[1];
        }
        res[i] = solution(events);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}