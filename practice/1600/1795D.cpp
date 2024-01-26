#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
int N;

// fast exponentiation with mod
ll modPow(ll base, ll exp) {
    ll res = 1;
    ll pow = base;
    while (exp) {
        if (exp & 1) {
            res = res * pow % MOD;
        }
        pow = pow * pow % MOD;
        exp >>= 1;
    }
    return res;
}

// Euler's theorem for modular division
ll modDiv(ll x, ll y) {
    return x * modPow(y, MOD - 2) % MOD;
}

// C = # of ccs, we have C choose (C/2) ways of picking colors. Assume the majority color is fixed for the 3 cases below
// all big: 3 ways to color
// one big, two medium: 2 ways to color
// one big, one medium, one small: 1 ways to color
ll solution(vector<int>& v) {
    ll res = 1;
    for (int i=0; i<N; i+=3) {
        vector<int> w = {v[i], v[i+1], v[i+2]};
        sort(w.begin(), w.end());
        if (w[0] == w[1] && w[1] == w[2]) {
            res *= 3;
        }
        else if (w[0] == w[1]) {
            res *= 2;
        }
        else {
            res *= 1;
        }
        res %= MOD;
    }
    ll num = 1;
    for (int i=1; i<=N/3; ++i) {
        num = num * i % MOD;
    }
    ll denom = 1;
    for (int i=1; i<=N/6; ++i) {
        denom = denom * i % MOD;
    }
    denom = denom * denom % MOD;
    ll choose = modDiv(num, denom);
    res = res * choose % MOD;
    return res;
}

int main() {
    cin >> N;
    vector<int> v(N);
    for (auto& x : v) {
        cin >> x;
    }
    cout << solution(v) << endl;
    return 0;
}