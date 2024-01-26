#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;
typedef long long ll;

// stores pyramid of prefix sums for each row
vector<vector<ll>> pref;
// maps <num, <row, col>> 
unordered_map<int, pair<int,int>> posMap;

// precompute the pyramid since its the same for all test cases
// prefix sum of rows above, as you go up l-- and keep r
ll solution(int n) {
    ll res = 0;
    int row = posMap[n].first;
    // l and r are inclusive
    int l = posMap[n].second;
    int r = posMap[n].second;
    while (row) {
        res += pref[row][r] - pref[row][l-1];
        l = max(1, l-1);
        r = min(row-1, r);
        --row;
    }
    return res;
}

int main() {
    // precompute pyramid
    ll x = 1;
    pref.resize(2024, vector<ll>(2024, 0));
    for (int i=1; i<=2023; ++i) {
        for (int j=1; j<=i; ++j) {
            pref[i][j] = x * x;
            pref[i][j] += pref[i][j-1];
            posMap[x] = {i, j};
            ++x;
        }
    }
    // test cases
    int T, n;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n;
        res[i] = solution(n);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}