#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// query corners, tells you which diagonal the mine is in
// query top left and bottom right tells gives you the positive diagonal
// query top right gives you negative diagonal, then one must exist on either intersection
void solve(int n, int m) {
    int sum1, sum2, diff, resp;
    // query top left:
    cout << "? " << 1 << " " << 1 << endl;
    cin >> sum1;
    if (sum1 == 0) {
        cout << "! " << 1 << " " << 1 << endl;
        return;
    }
    // query bottom right:
    cout << "? " << n << " " << m << endl;
    cin >> sum2;
    if (sum2 == 0) {
        cout << "! " << n << " " << m << endl;
        return;
    }
    sum2 = (n - 1) + (m - 1 - sum2);
    // query top right:
    cout << "? " << 1 << " " << m << endl;
    cin >> diff;
    if (diff == 0) {
        cout << "! " << 1 << " " << m << endl;
        return;
    }
    if (diff == n + m - 2) {
        cout << "! " << n << " " << 1 << endl;
        return;
    }
    diff = diff - m + 1;
    vector<vector<int>> inters;
    // try making intersection one:
    int i1 = max(0, sum1 + (-1 * diff));
    if (i1 % 2 == 0) {
        int x = i1 / 2;
        int y = sum1 - x;
        inters.push_back({x, y});
    }
    // try making intersection two:
    int i2 = max(0, sum2 + (-1 * diff));
    if (i2 % 2 == 0) {
        int x = i2 / 2;
        int y = sum2 - x;
        inters.push_back({x, y});
    }
    // query one intersection:
    int row = max(1, inters[0][1] + 1);
    int col = max(1, inters[0][0] + 1);
    cout << "? " << row << " " << col << endl;
    cin >> resp;
    // answer:
    if (resp == 0) {
        cout << "! " << row << " " << col << endl;
    }
    else {
        row = max(1, inters[1][1] + 1);
        col = max(1, inters[1][0] + 1);
        cout << "! " << row << " " << col << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int n, m;
    while (T--) {
        cin >> n >> m;
        solve(n, m);
    }
    return 0;
}