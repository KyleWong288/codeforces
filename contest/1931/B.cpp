#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <numeric>
using namespace std;
typedef long long ll;

int n;

int solve(vector<int>& a) {
    int sum = 0;
    int cap = 0;
    int step = accumulate(a.begin(), a.end(), 0) / n;
    for (int i=n-1; i>=0; --i) {
        cap += step;
        sum += a[i];
        if (sum > cap) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n;
        vector<int> a(n);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << (r ? "YES\n" : "NO\n");
    }
    return 0;
}