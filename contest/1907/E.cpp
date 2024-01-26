#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// base: you can always do (n, 0, 0), then subtract from one pos and add to another pos to create new triplets
// we can do +/- ops between two digits in the same position, as long as we dont go (9 -> 0) or (0 -> 9)
// this means each digit position is independent
// for each digit in n, compute all triplets that sum to it -> (digit + 2) choose 2
ll solution(ll n) {
    ll res = 1;
    while (n) {
        int digit = n % 10;
        ll ways = (digit + 2) * (digit + 1) / 2;
        res *= ways;
        n /= 10;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    ll n;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n;
        res[i] = solution(n);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}