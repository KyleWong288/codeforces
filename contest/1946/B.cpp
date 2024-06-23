#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <numeric>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
int N, K;

// find mss, and then insert the mss into that subarray to get a new mss
int solve(vector<ll>& a) {
    ll mss = 0;
    ll sum = 0;
    ll res = 0;
    for (auto& x : a) {
        sum += x;
        mss = max(mss, sum);
        if (sum < 0) sum = 0;
        res = (res + x + MOD) % MOD;
    }
    ll spam = mss;
    for (int i=0; i<K; ++i) {
        spam = (spam * 2LL) % MOD;
    }
    res %= MOD;
    spam %= MOD;
    mss %= MOD;
    res = (res + spam) % MOD;
    res = (res - mss + MOD) % MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
        vector<ll> a(N);
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