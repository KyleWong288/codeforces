#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, Q;

// psum track # of unique vals -> ps[i] = # of unique values from [0, i]
// to find index: if a[l] != a[r], we good
// else: bs from [l, r] to find the index j such that ps[j] = ps[l] + 1 (new char)
void solve(vector<int>& a, vector<vector<int>>& queries) {
    vector<int> ps(N, 1);
    for (int i=1; i<N; ++i) {
        ps[i] = ps[i-1] + (a[i] != a[i-1]);
    }
    vector<vector<int>> res(Q, vector<int>(2));
    for (int q=0; q<Q; ++q) {
        int l = queries[q][0] - 1;
        int r = queries[q][1] - 1;
        if (ps[l] == ps[r]) {
            res[q][0] = -2;
            res[q][1] = -2;
        }
        else if (a[l] != a[r]) {
            res[q][0] = l;
            res[q][1] = r;
        }
        else {
            int idx = upper_bound(ps.begin() + l, ps.begin() + r, ps[l]) - ps.begin();
            res[q][0] = idx;
            res[q][1] = r;
        }
    }
    //cout << "ANS:" << endl;
    for (auto& r : res) {
        cout << r[0] + 1 << " " << r[1] + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        cin >> Q;
        vector<vector<int>> queries(Q, vector<int>(2));
        for (auto& q : queries) {
            cin >> q[0] >> q[1];
        }
        solve(a, queries);
        cout << endl;
    }
    return 0;
}