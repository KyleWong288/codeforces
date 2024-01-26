#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M, Q;

// track prefix range, # of * in prefix range, # of * in total
// query answer = (# of *) - (# of * in prefix range)
// computing update: update based on the boundary cell of the prefix range, and the actual updated cell
void solution(vector<vector<bool>>& grid, vector<pair<int,int>>& queries) {
    vector<int> res(Q);
    // get base:
    int total = 0;
    int inside = 0;
    for (int r=0; r<N; ++r) {
        for (int c=0; c<M; ++c) {
            total += grid[r][c];
        }
    }
    for (int c=0; c<M; ++c) {
        for (int r=0; r<N; ++r) {
            int pos = c * N + r;
            if (pos < total) {
                inside += grid[r][c];
            }
        }
    }
    // answer queries:
    for (int q=0; q<Q; ++q) {
        int qr = queries[q].first - 1;
        int qc = queries[q].second - 1;
        int pos = qc * N + qr;
        if (grid[qr][qc]) {
            int tc = (total - 1) / N;
            int tr = (total - 1) % N;
            if (grid[tr][tc]) {
                inside--;
            }
            total--;
            grid[qr][qc] = 0;
            if (pos <= total - 1) {
                inside--;
            }
        }
        else {
            if (pos <= total - 1) {
                inside++;
            }
            total++;
            grid[qr][qc] = 1;
            int tc = (total - 1) / N;
            int tr = (total - 1) % N;
            if (grid[tr][tc]) {
                inside++;
            }
        }
        res[q] = total - inside;
    }
    for (auto& r : res) {
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> Q;
    string line;
    vector<vector<bool>> grid(N, vector<bool>(M, 0));
    for (int i=0; i<N; ++i) {
        cin >> line;
        for (int j=0; j<M; ++j) {
            if (line[j] == '*') {
                grid[i][j] = 1;
            }
        }
    }
    vector<pair<int,int>> queries(Q);
    for (auto& pr : queries) {
        cin >> pr.first >> pr.second;
    }
    solution(grid, queries);
    return 0;
}