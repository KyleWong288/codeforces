#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
#include <unordered_map>
using namespace std;
typedef long long ll;

vector<bool> isPrime;
int N;

// see if we can evenly divide the prime factors -> freq of each prime factor should be divisible by N
int solution(vector<int>& v) {
    unordered_map<int,int> freq;
    for (auto& x : v) {
        int n = x;
        int end = sqrt(n);
        for (int i=2; i<=end; ++i) {
            while (n && (n % i) == 0) {
                freq[i]++;
                n /= i;
            }
        }
        if (isPrime[n]) { // remaining is prime
            freq[n]++;
        }
    }
    for (auto& pr : freq) {
        if (pr.second % N) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // sieve
    isPrime.resize(1e6+1, 1);
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i=2; i<=1e6; ++i) {
        if (isPrime[i]) {
            for (int j=i+i; j<=1e6; j+=i) {
                isPrime[j] = 0;
            }
        }
    }
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> v(N);
        for (auto& x : v) {
            cin >> x;
        }
        res[i] = solution(v);
    }
    for (auto& r : res) {
        if (r) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}