#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// FAIL

// x and n need the same sig bit
// x needs to be all 1s and then all 0s
// if bit is set in x but not in n, fail
// if bit is set in n but not in x, simulate add and carry process
ll solution(ll n, ll x) {
    // edge cases: n = x, n = 0, x = 0
    if (n == x) {
        return n;
    }
    if (n == 0) {
        return -1;
    }
    if (x == 0) {
        ll res = 1;
        while (res <= n) {
            res <<= 1;
        }
        return res;
    }
    // check same sig bit
    for (int i=61; i>=0; --i) {
        bool setN = (n & (1LL << i));
        bool setX = (x & (1LL << i));
        if (setN != setX) {
            return -1;
        }
        if (setN) { break; }
    }
    // check x is 1s and 0s
    int b = 0;
    for (b=0; b<64; ++b) {
        if (x & (1LL << b)) {
            break;
        }
    }
    for (b; b<64; ++b) {
        if ((x & (1LL << b)) == 0) {
            break;
        }
    }
    for (b; b<64; ++b) {
        if (x & (1LL << b)) {
            return -1;
        }
    }
    // check all set bits in x are also set in n
    for (int i=0; i<64; ++i) {
        bool setN = (n & (1LL << i));
        bool setX = (x & (1LL << i));
        if (setX && !setN) {
            return -1;
        }
    }
    // simulate add and carry
    ll res = 0;
    for (int i=0; i<64; ++i) {
        bool setN = (n & (1LL << i));
        bool setX = (x & (1LL << i));
        if (setN && !setX) {
            while (i < 64 && setN && !setX) {
                ++i;
                setN = (n & (1LL << i));
                setX = (x & (1LL << i));
            }
            if (setN && setX) { // case where n increments to the next power of 2
                return -1;
            }
            res += (1LL << i);
        }
        if (setN && setX) {
            while (i < 64 && setN && setX) {
                res += (1LL << i);
                ++i;
                setN = (n & (1LL << i));
                setX = (x & (1LL << i));
            }
        }
    }
    return res;    
}

int main() {
    int T;
    cin >> T;
    ll n, x;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> x;
        res[i] = solution(n, x);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}