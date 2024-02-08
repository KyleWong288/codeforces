#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

int n, m, k;

// grab unique to a, unique to b, then we can always grab those that exist in both
// so just check that # of unique in one <= k/2
int solve(set<int>& a, set<int>& b) {
    int unqA = 0;
    int unqB = 0;
    set<int> have;
    for (auto& x : a) {
        unqA += (x <= k && b.find(x) == b.end());
        if (x <= k) have.insert(x);
    }
    for (auto& x : b) {
        unqB += (x <= k && a.find(x) == a.end());
        if (x <= k) have.insert(x);
    }
    return (unqA <= k/2 && unqB <= k/2 && have.size() == k);
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int x;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> m >> k;
        set<int> a;
        set<int> b;
        for (int j=0; j<n; ++j) {
            cin >> x;
            a.insert(x);
        }
        for (int j=0; j<m; ++j) {
            cin >> x;
            b.insert(x);
        }
        res[i] = solve(a, b);
    }
    for (auto& r : res) {
        cout << (r ? "YES\n" : "NO\n");
    }
    return 0;
}