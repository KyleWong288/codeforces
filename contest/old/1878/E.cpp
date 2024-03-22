#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N, Q;

// construct parent vectors: each i has a parent vector of size 32
// if bit b is set in v[i], then parent[i][b] = next highest index that has bit b set to 0
// answer query: CumAnd starts at v[i], while CumAnd >= k, follow the parent vector to the next bit lost
void solution(vector<int>& v, vector<pair<int,int>>& queries) {
    // build parent vectors:
    vector<vector<int>> par(N);
    vector<int> build(32, N);
    for (int i=N-1; i>=0; --i) {
        par[i] = build;
        for (int b=0; b<32; ++b) {
            int set = v[i] & (1 << b);
            if (!set) {
                build[b] = i;
            }
        }
    }
    // answer queries:
    vector<int> res(Q);
    for (int i=0; i<Q; ++i) {
        int idx = queries[i].first - 1;
        int k = queries[i].second;
        int cumAnd = v[idx];
        if (cumAnd < k) {
            res[i] = -1;
            continue;
        }
        while (cumAnd >= k) {
            int nextIdx = N;
            for (int b=0; b<32; ++b) {
                // only try jumping to next bit if its set in cumAnd
                int set = cumAnd & (1 << b);
                if (set) {
                    nextIdx = min(nextIdx, par[idx][b]);
                }
            }
            idx = nextIdx;
            if (idx >= N) { break; }
            cumAnd &= v[idx];
        }
        res[i] = idx;
    }
    for (auto& x : res) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> N;
        vector<int> v(N);
        for (auto& x : v) {
            cin >> x;
        }
        cin >> Q;
        vector<pair<int,int>> q(Q);
        for (auto& x : q) {
            cin >> x.first >> x.second;
        }
        solution(v, q);
    }
    return 0;
}