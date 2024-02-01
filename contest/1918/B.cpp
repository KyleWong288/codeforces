#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// sort by (a[i] + b[i]) sum
void solve(vector<int>& a, vector<int>& b) {
    vector<vector<int>> prs(N);
    for (int i=0; i<N; ++i) {
        prs[i] = {a[i] + b[i], i};
    }
    sort(prs.begin(), prs.end());
    for (int i=0; i<N; ++i) {
        int idx = prs[i][1];
        cout << a[idx] << " ";
    }
    cout << endl;
    for (int i=0; i<N; ++i) {
        int idx = prs[i][1];
        cout << b[idx] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> a(N);
        vector<int> b(N);
        for (auto& x : a) {
            cin >> x;
        }
        for (auto& x : b) {
            cin >> x;
        }
        solve(a, b);
    }
    return 0;
}