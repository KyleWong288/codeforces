#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// normal numbers: n / a = b, so both a and b are divisors, so we have even amount
// perfect squares: n / a = a, so we only get 1 divisor, so we have odd amount
// make xor prefix array, for a given right endpt r, we can take all left endpt l minus endpts that cause a perfect square
ll solution(vector<int>& v) {
    ll res = 0;
    vector<int> pref(N+1, 0);
    vector<int> freq(4*N+1, 0);
    freq[0] = 1;
    for (int i=0; i<N; ++i) {
        pref[i+1] = pref[i] ^ v[i];
        // brute force try all perfect squares
        ll leftEnds = i+1;
        for (int ps = 0; ps*ps <= 2*N; ++ps) {
            int x = ps * ps;
            // pref[l-1] ^ pref[r] = x, so pref[l-1] = pref[r] ^ x
            int lVal = pref[i+1] ^ x;
            leftEnds -= freq[lVal];
        }
        ++freq[pref[i+1]];
        res += leftEnds;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> v(N);
        for (auto& x : v) {
            cin >> x;
        }
        res[i] = solution(v);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}