#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int n;

// prev, cur, want mult such that cur * mult > prev, so mult = prev / cur
ll solve(vector<ll>& a) {
    for (int i=1; i<n; ++i) {
        ll mult = (a[i-1] + a[i] - 1) / a[i];
        if (a[i] * mult == a[i-1]) ++mult;
        a[i] *= mult;
    }
    return a[n-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n;
        vector<ll> a(n);
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