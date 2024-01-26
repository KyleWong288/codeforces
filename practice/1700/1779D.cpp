#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

int N, M;
vector<int> segtree;

// i is index in segtree, tl and tr is range in v
void build(vector<int>& v, int i, int tl, int tr) {
    if (tl == tr) {
        segtree[i] = v[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v, 2*i+1, tl, tm);
    build(v, 2*i+2, tm+1, tr);
    segtree[i] = max(segtree[2*i+1], segtree[2*i+2]);
}

// i is index in segtree, tl and tr is range in v, l and r are fixed range query
int query(int i, int tl, int tr, int l, int r) {
    if (tl > r || tr < l) {
        return 0;
    }
    if (tl >= l && tr <= r) {
        return segtree[i];
    }
    int tm = (tl + tr) / 2;
    int vl = query(2*i+1, tl, tm, l, r);
    int vr = query(2*i+2, tm+1, tr, l, r);
    return max(vl, vr);
}

// rmq on consecutive points of the same value, if the rmq is larger we need an extra razor
// use segtree for rmq yaaaayy
int solution(vector<int>& a, vector<int>& b, vector<int>& razors) {
    for (int i=0; i<N; ++i) {
        if (a[i] < b[i]) {
            return 0;
        }
    }
    map<int,int> freq;
    for (auto& r : razors) {
        freq[r]++;
    }
    // maps <value, most recently found left endpoint>
    map<int, int> leftPt;
    // perform range queries for each value:
    segtree.clear();
    segtree.resize(4*N, 0);
    build(b, 0, 0, N-1);
    for (int i=0; i<N; ++i) {
        if (a[i] == b[i]) { continue; }
        if (leftPt.find(b[i]) == leftPt.end()) {
            freq[b[i]]--;
        }
        else {
            int rmq = query(0, 0, N-1, leftPt[b[i]], i);
            if (rmq > b[i]) {
                freq[b[i]]--;
            }
        }
        if (freq[b[i]] < 0) {
            return 0;
        }
        leftPt[b[i]] = i;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        vector<int> b(N);
        for (auto& x : b) {
            cin >> x;
        }
        cin >> M;
        vector<int> q(M);
        for (auto& x : q) {
            cin >> x;
        }
        res[i] = solution(a, b, q);
    }
    for (auto& r : res) {
        if (r) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}