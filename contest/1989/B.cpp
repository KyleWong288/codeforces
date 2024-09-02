#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// for each starting point i in b, find the longest b[i,j] in a via 2ptr match
// then prepend b[0, i-1] and append b[j+1, n-1]
int solve(string& a, string& b) {
    int n = a.size(), m = b.size();
    int res = 1e9;
    for (int i=0; i<m; ++i) {
        int pa = 0, pb = i;
        int matches = 0;
        while (pb < m) {
            while (pa < n && a[pa] != b[pb]) ++pa;
            if (pa < n) {
                ++matches;
                ++pa;
                ++pb;
            }
            else {
                break;
            }
        }
        res = min(res, m - matches + n);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    string a, b;
    for (int i=0; i<T; ++i) {
        cin >> a >> b;
        res[i] = solve(a, b);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}