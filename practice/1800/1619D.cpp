#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <numeric>
using namespace std;
typedef long long ll;

int M, N;

// maximize the min, obvious bs
// we need to satisfy n columns with n-1 rows, so one row needs 2, rest need 1
// greedily pick rows: start with a row that satisfies 2 cols, then only pick rows that satisfy at least one new col
// thus, it works iff we have full coverage of cols and theres a row with at least 2 cols
int solution(vector<vector<int>>& p) {
    int l = 1;
    int r = 1e9;
    while (l <= r) {
        int m = (l + r) / 2;
        vector<int> covered(N, 0);
        int maxFreq = 0;
        for (int i=0; i<M; ++i) {
            int freq = 0;
            for (int j=0; j<N; ++j) {
                if (p[i][j] >= m) {
                    covered[j] = 1;
                    ++freq;
                }
            }
            maxFreq = max(freq, maxFreq);
        }
        int colsCovered = accumulate(covered.begin(), covered.end(), 0);
        if (colsCovered == N && maxFreq > 1) {
            l = m+1;
        }
        else {
            r = m-1;
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> M >> N;
        vector<vector<int>> p(M, vector<int>(N));
        for (int r=0; r<M; ++r) {
            for (int c=0; c<N; ++c) {
                cin >> p[r][c];
            }
        }
        res[i] = solution(p);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}