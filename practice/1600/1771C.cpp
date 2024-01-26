#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_set>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;

int N;
vector<int> primes;

// godly solution: product(arr) == lcm(arr) iff NO, but overflow
// brute force probably too slow: care about all primes in [2, sqrt(1e9)], about 3400
// also need to track primes larger than sqrt(1e9)
int solution(vector<int>& a) {
    unordered_set<int> have;
    for (auto& x : a) {
        for (auto& p : primes) {
            if (x % p == 0) {
                if (have.find(p) != have.end()) {
                    return 1;
                }
                have.insert(p);
                while (x % p == 0) {
                    x /= p;
                }
            }
            if (x == 1) { break; }
        }
        // large prime factor leftover
        if (x > 1) {
            if (have.find(x) != have.end()) {
                return 1;
            }
            have.insert(x);
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    // precompute set of primes under sqrt(1e9) with sieve
    int end = sqrt(1e9) + 100;
    vector<bool> isPrime(end, 1);
    for (int i=2; i<end; ++i) {
        if (isPrime[i]) {
            for (int j=i+i; j<end; j+=i) {
                isPrime[j] = 0;
            }
            primes.push_back(i);
        }
    }
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solution(a);
    }
    for (auto& r : res) {
        cout << (r ? "YES\n" : "NO\n");
    }
    return 0;
}