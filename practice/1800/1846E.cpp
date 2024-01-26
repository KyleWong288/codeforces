#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;

// brute force over every length sequence (up to ~60 since 2^60)
// for each length, binary search on possible k value
// longer sequences have lower bs range <- faster runtime
// instead of taking power, do next = (cur * k) + 1  <- faster and helps detect overflow
int solution(ll n) {
    for (ll i=3; i<=60; ++i) {
        ll l = 2;
        ll r = pow(1e18, 1.0/(i-1)) + 1;
        while (l <= r) {
            ll m = (l + r) / 2;
            ll sum = 0;
            for (int j=0; j<i; ++j) {
                // overflow check:
                if (sum != 0 && (ll)2e18 / sum < m) {
                    sum = 2e18;
                    break;
                }
                sum = (sum * m) + 1;
            }
            if (sum < n) {
                l = m + 1;
            }
            else if (sum > n) {
                r = m - 1;
            }
            else {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    ll n;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n;
        res[i] = solution(n);
    }
    for (auto& r : res) {
        cout << (r ? "YES\n" : "NO\n");
    }
    return 0;
}