#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// fail case: different parity between k and (n-1) + (m-1), or k < (n-1) + (m-1)
// we can spam cycle of 4, and take a zig zag to adjust by 2 moves, make an edge path for a simple guarantee
void solution(int n, int m, int k) {
    vector<vector<char>> edgesR(n, vector<char>(m-1, 'R'));
    vector<vector<char>> edgesC(n-1, vector<char>(m, 'B'));
    int pathLen = (n-1) + (m-1);
    if ((pathLen % 2) != (k % 2) || k < pathLen) {
        cout << "NO" << endl;
        return;
    }
    // construct edge path:
    for (int i=1; i<m-1; i+=2) {
        edgesR[0][i] = 'B';
    }
    if ((m-1) % 2 == 0) {
        for (int i=0; i<n-1; i+=2) {
            edgesC[i][m-1] = 'R';
        }
    }
    else {
        for (int i=1; i<n-1; i+=2) {
            edgesC[i][m-1] = 'R';
        }
    }
    // zigzag case:
    if (pathLen % 4 != k % 4) {
        edgesC[0][0] = 'R';
        edgesR[1][0] = 'B';
        edgesC[0][1] = 'R';
    }
    cout << "YES" << endl;
    for (auto& x : edgesR) {
        for (auto& y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    for (auto& x : edgesC) {
        for (auto& y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int n, m, k;
    while (T--) {
        cin >> n >> m >> k;
        solution(n, m, k);
    }
    return 0;
}