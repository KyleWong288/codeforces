#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, Q;

// greedily try to set from large bit to small bit, find cost to set bit b in all a[i] to 1
// if bit b in a[i] switches from 0 to 1, the suffix becomes 0, future costs become powers of 2
// else, future cost still depends on original value of a[i]
void solution(vector<ll>& arr, vector<ll>& queries) {
    vector<ll> res(Q, 0);
    for (ll i=0; i<Q; ++i) {
        ll ans = 0;
        vector<ll> a = arr;
        ll k = queries[i];
        for (ll b=61; b>=0; --b) {
            ll ops = 0;
            for (auto& x : a) {
                if (((x >> b) & 1LL) == 0) {
                    ll pow = (1LL << b);
                    ll suff = x & (pow - 1);
                    ops += pow - suff;
                }
                if (ops > k) { break; }
            }
            if (ops > k) { continue; }
            // possible, set all bits to 1
            for (auto& x : a) {
                if (((x >> b) & 1LL) == 0) {
                    ll pow = (1LL << b);
                    ll suff = x & (pow - 1);
                    ll diff = pow - suff;
                    k -= diff;
                    x += diff;
                }
            }
            ans += (1LL << b);
        }
        res[i] = ans;
    }
    for (auto& r : res) {
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> Q;
    vector<ll> a(N);
    for (auto& x : a) {
        cin >> x;
    }
    vector<ll> q(Q);
    for (auto& x : q) {
        cin >> x;
    }
    solution(a, q);
    return 0;
}