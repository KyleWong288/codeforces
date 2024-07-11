#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

int solve(vector<int>& a) {
    int mx = max(a[0], a[1]);
    for (int i=1; i<N-1; ++i) {
        mx = min(mx, max(a[i], a[i+1]));
    }
    return mx - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}