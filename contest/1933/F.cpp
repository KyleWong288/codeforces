#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// last col is always empty -> reframe problem to how fast can we get to last col
// this means up and down arent as important as moving right
// doesn't make sense to revisit cell (aka spam down & up)??
int solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        res[i] = solve();
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}