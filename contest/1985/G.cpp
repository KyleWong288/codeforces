#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;
ll l, r, k;
vector<int> setSizes = {0, 10, 5, 4, 3, 2, 2, 2, 2, 2};


ll modExp(int base, ll pow) {
    ll res = 1;
    ll mult = base;
    for (int i=0; i<63; ++i) {
        if ((pow >> i) & 1) {
            res = (res * mult) % MOD;
        }
        mult = (mult * mult) % MOD;
    }
    return res;
}

// k >= 10 never works: D(k*n) increases at most by factor of 9 (all 0s -> all 9s), but k*D(n) increases by at least 10
// know: not carrying implies good, digits are just independent
// guess: carrying implies failure
// thus, we can use any digit d such that d * k <= 9
// counting: (# of usable digits) ^ (n) - 1, sum of powers
int solve() {
    if (k >= 10) return 0;
    int setSize = setSizes[k];
    ll right = modExp(setSize, r);
    ll left = modExp(setSize, l);
    return (right - left + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> l >> r >> k;
        res[i] = solve();
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}