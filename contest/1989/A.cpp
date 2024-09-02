#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int>> pts(N, vector<int>(2));
    for (auto& pt : pts) {
        cin >> pt[0] >> pt[1];
    }
    vector<int> res(N);
    for (int i=0; i<N; ++i) {
        int x = pts[i][0], y = pts[i][1];
        int time = abs(x);
        int newY = y - time + 1;
        if (newY >= -1 * time) res[i] = 1;
    }
    for (auto& x : res) {
        if (x) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}