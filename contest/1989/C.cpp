#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// cases: (1,0), (0,1), (1,-1), (-1,1), just go 1
// (0,-1) and (-1,0), just go 0
// (1,1) and (-1,-1) greedily use to balance, (0,0) useless
int solve(vector<vector<int>>& a) {
    int mov0 = 0, mov1 = 0, plus = 0, minus = 0;
    for (auto& pr : a) {
        if (pr[0] == 1 && pr[1] <= 0) ++mov0;
        else if (pr[1] == 1 && pr[0] <= 0) ++mov1;
        else if (pr[1] + pr[0] == 2) ++plus;
        else if (pr[1] + pr[0] == -2) ++minus;
    }
    while (minus--) {
        if (mov0 > mov1) --mov0;
        else --mov1;
    }
    while (plus--) {
        if (mov0 > mov1) ++mov1;
        else ++mov0;
    }
    return min(mov0, mov1);
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<vector<int>> a(N, vector<int>(2));
        for (auto& pr : a) {
            cin >> pr[0];
        }
        for (auto& pr : a) {
            cin >> pr[1];
        }
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}