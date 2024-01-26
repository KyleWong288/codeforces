#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M;

// ALWAYS better to take 1 coin operation as long as its in the right direction
// prefix sum 1: this is the vector a itself
// prefix sum 2: stores the saves from coin operations l->r
// prefix sum 3: stores the saves from coin operations r->l
void solution(vector<ll>& a, vector<vector<ll>>& queries) {
    vector<ll> saveLR(N, 0);
    for (int i=0; i<N-1; ++i) {
        if (i == 0 || a[i+1] - a[i] < a[i] - a[i-1]) {
            saveLR[i] = a[i+1] - a[i] - 1;
        }
    }
    vector<ll> saveRL(N, 0);
    for (int i=N-1; i>0; --i) {
        if (i == N-1 || a[i] - a[i-1] < a[i+1] - a[i]) {
            saveRL[i] = a[i] - a[i-1] - 1;
        }
    }
    vector<ll> prefLR(N+1, 0);
    for (int i=0; i<N; ++i) {
        prefLR[i+1] = prefLR[i] + saveLR[i];
    }
    vector<ll> prefRL(N+1, 0);
    for (int i=N-1; i>=0; --i) {
        prefRL[i] = prefRL[i+1] + saveRL[i];
    }
    vector<ll> res(M);
    for (int q=0; q<M; ++q) {
        int l = queries[q][0] - 1;
        int r = queries[q][1] - 1;
        if (l < r) {
            res[q] = (a[r] - a[l]) - (prefLR[r] - prefLR[l]);
        }
        else {
            swap(l, r);
            res[q] = (a[r] - a[l]) - (prefRL[l+1] - prefRL[r+1]);
        }
    }
    for (auto& r : res) {
        cout << r << endl;
    }
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
        cin >> M;
        vector<vector<ll>> queries(M, vector<ll>(2));
        for (auto& q : queries) {
            cin >> q[0] >> q[1];
        }
        solution(a, queries);
    }
    return 0;
}