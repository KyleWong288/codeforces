#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// cases (a,b): (1,0), (0,1), (1,1), (0,0) ... we only care about mismatches
// (1,1) and (0,0): don't care, they will be the same
// (1,0) and (0,1): x = 1 at this bit will flip -> this means we can control if a or b gets a power of 2
// how to solve if x not bounded by r? give a the largest mismatch, give b the remaining mismatches
// general idea still holds with bound r: whoever got the largest mismatch should get fewer and lower mismatches
ll solve(ll a, ll b, ll r) {
    // give A largest mismatch:
    ll x = 0;
    int cntMiss = 0;
    for (int i=63; i>=0; --i) {
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;
        if (bitA != bitB) {
            cntMiss++;
            ll newX = x + (1LL << i);
            if (newX > r) {
                continue;
            }
            else if (cntMiss == 1) {
                if (bitA == 0) {
                    x += (1LL << i);
                }
            }
            else {
                if (bitB == 0) {
                    x += (1LL << i);
                }
            }
        }
    }
    ll resA = abs((a ^ x) - (b ^ x));
    // give B largest mismatch:
    x = 0;
    cntMiss = 0;
    for (int i=63; i>=0; --i) {
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;
        if (bitA != bitB) {
            cntMiss++;
            ll newX = x + (1LL << i);
            if (newX > r) {
                continue;
            }
            else if (cntMiss == 1) {
                if (bitB == 0) {
                    x += (1LL << i);
                }
            }
            else {
                if (bitA == 0) {
                    x += (1LL << i);
                }
            }
        }
    }
    ll resB = abs((a ^ x) - (b ^ x));
    return min(resA, resB);
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    ll a, b, r;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> a >> b >> r;
        res[i] = solve(a, b, r);
    }
    for (auto& x : res) {
        cout << x << endl;
    }
    return 0;
}