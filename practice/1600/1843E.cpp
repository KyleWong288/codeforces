#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N, M, Q;


// binary search on answering queries, then use prefix sum to see if a range is beautiful
int solution(vector<pair<int,int>>& ranges, vector<int>& queries) {
    vector<int> v(N+1, 0);
    int l = 0;
    int r = Q-1;
    while (l <= r) {
        int m = (l + r) / 2;
        for (auto& x : v) { x = 0; }
        // answer queries:
        for (int q=0; q<=m; ++q) {
            v[queries[q]] = 1;
        }
        // get prefix sum:
        for (int i=1; i<=N; ++i) {
            v[i] += v[i-1];
        }
        // check ranges:
        bool hasBeautiful = false;
        for (auto& seg : ranges) {
            if (v[seg.second] - v[seg.first-1] > (seg.second - seg.first + 1) / 2) {
                hasBeautiful = true;
                break;
            }
        }
        if (hasBeautiful) {
            r = m-1;
        }
        else {
            l = m+1;
        }
    }
    if (l == Q) {
        return -1;
    }
    return l+1;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<pair<int,int>> ranges(M);
        for (auto& x : ranges) {
            cin >> x.first >> x.second;
        }
        cin >> Q;
        vector<int> queries(Q);
        for (auto& x : queries) {
            cin >> x;
        }
        res[i] = solution(ranges, queries);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}