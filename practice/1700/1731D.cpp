#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int N, M;

bool possible(vector<vector<int>>& g, int L) {
    // construct 2D prefix sum:
    vector<vector<int>> pref(N, vector<int>(M, 0));
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (g[i][j] < L) {
                pref[i][j] = 1;
            }
            if (i) { pref[i][j] += pref[i-1][j]; }
            if (j) { pref[i][j] += pref[i][j-1]; }
            if (i && j) { pref[i][j] -= pref[i-1][j-1]; }
        }
    }
    // try all LxL squares:
    for (int i=L-1; i<N; ++i) {
        for (int j=L-1; j<M; ++j) {
            int sum = pref[i][j];
            if (i-L >= 0) { sum -= pref[i-L][j]; }
            if (j-L >= 0) { sum -= pref[i][j-L]; }
            if (i-L >= 0 && j-L >= 0) { sum += pref[i-L][j-L]; }
            if (sum == 0) {
                return 1;
            }
        }
    }
    return 0;
}

// binary search on L, each guess use 2D prefix sum and try every possible LxL square
int solution(vector<vector<int>>& g) {
    int l = 1;
    int r = min(N, M);
    while (l <= r) {
        int m = (l + r) / 2;
        bool b = possible(g, m);
        if (b) {
            l = m+1;
        }
        else {
            r = m-1;
        }
    }
    return r;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<vector<int>> g(N, vector<int>(M, 0));
        for (int r=0; r<N; ++r) {
            for (int c=0; c<M; ++c) {
                cin >> g[r][c];
            }
        }
        res[i] = solution(g);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}