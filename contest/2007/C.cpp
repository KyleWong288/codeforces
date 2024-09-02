#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <numeric>
using namespace std;
typedef long long ll;

ll n, a, b;

// how to solve with one number a? get the smallest mod diff between mods
// how to solve with two numbers a & b? smallest denom is now gcd(a,b), so do same
ll solve(vector<ll>& arr) {
    ll g = gcd(a, b);
    vector<int> mods(n);
    for (int i=0; i<n; ++i) {
        mods[i] = arr[i] % g;
    }
    sort(mods.begin(), mods.end());
    ll res = mods[n-1] - mods[0];
    for (int i=1; i<n; ++i) {
        res = min(res, mods[i-1] + g - mods[i]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> a >> b;
        vector<ll> arr(n);
        for (auto& x : arr) cin >> x;
        res[i] = solve(arr);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}