#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;
int N, M;

ll modpow(ll base, ll exp) {
    ll res = 1;
    ll pow = base;
    while (exp) {
        if (exp & 1) {
            res = res * pow % MOD;
        }
        exp >>= 1;
        pow = pow * pow % MOD;
    }
    return res;
}

ll moddiv(ll a, ll b) {
    ll res = a * modpow(b, MOD-2) % MOD;
    return res;
}

// batch by value, then sort and sliding window
// the conditions mean that our window needs to be consecutive values
// for each right endpoint, add the # of subarrays that have that right endpoint as the last student -> final ans is sum of these
ll solution(vector<ll>& a) {
    ll res = 0;
    map<ll, ll> freq;
    for (auto& x : a) {
        freq[x]++;
    }
    // stores <value, freq>
    vector<pair<ll,ll>> batches;
    for (auto& pr : freq) {
        batches.push_back(pr);
    }
    ll l = 0;
    ll prod = 1;
    for (ll r=0; r<batches.size(); ++r) {
        prod = prod * batches[r].second % MOD;
        while (batches[r].first - batches[l].first >= M) {
            prod = moddiv(prod, batches[l].second);
            ++l;
        }
        if (r - l + 1 == M) {
            res += prod;
            res %= MOD;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solution(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}