#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, Q;

// greedily assign 1 bits to later indices, process queries in sorted order
// first pass to track forced 0 bits from OR
// second pass to assign 1 bits, if we need a new bit, always assign the 1 bit to the later index
// forced to assign to earlier index: later bit is a forced 0, or indices are the same
// chunk by value: for ex, (1, 2) can both take b so we assign 2, (1, 3) only 1 can take b so we assign 1, thus we should backtrack and only assign 1
void solution(vector<vector<int>>& queries) {
    // 0 is not set, 1 is set, -1 is can't use due to 0 in OR
    vector<vector<int>> use(N+1, vector<int>(32, 0));
    // chunks[i] is list of queries that have i as the smaller index
    vector<vector<vector<int>>> chunks(N+1);
    // compute forced 0 bits
    for (auto& q : queries) {
        int i1 = q[0], i2 = q[1], x = q[2];
        for (int b=30; b>=0; --b) {
            if (((x >> b) & 1) == 0) {
                use[i1][b] = -1;
                use[i2][b] = -1;
            }
        }
        chunks[i1].push_back(q);
    }
    for (int i=1; i<=N; ++i) {
        // compute forced 1 bits on index i
        for (auto& q : chunks[i]) {
            int i1 = q[0], i2 = q[1], x = q[2];
            for (int b=30; b>=0; --b) {
                if ((x >> b) & 1) {
                    if (use[i2][b] == -1 || i1 == i2) {
                        use[i1][b] = 1;
                    }
                }
            }
        }
        // compute remaining bits
        for (auto& q : chunks[i]) {
            int i1 = q[0], i2 = q[1], x = q[2];
            for (int b=30; b>=0; --b) {
                if ((x >> b) & 1) {
                    if (use[i1][b] == 1 || use[i2][b] == 1) { // no assign
                        continue;
                    }
                    else { // assign i2
                        use[i2][b] = 1;
                    }
                }
            }
        }
    }
    for (int i=1; i<=N; ++i) {
        int res = 0;
        for (int b=0; b<=30; ++b) {
            if (use[i][b] == 1) {
                res += (1 << b);
            }
        }
        cout << res << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> Q;
    vector<vector<int>> queries(Q, vector<int>(3));
    for (auto& q : queries) {
        cin >> q[0] >> q[1] >> q[2];
        if (q[1] < q[0]) {
            swap(q[0], q[1]);
        }
    }
    solution(queries);
    return 0;
}