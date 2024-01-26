#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <numeric>
using namespace std;
typedef long long ll;

int N;

// divisor question, think lcm or gcd
// we want c such that its divisible by as many consecutive b[i] as possible -> use a rolling lcm
// we want c such that it divides as many consecutive a[i] * b[i] as possible -> use a rolling gcd
// gcd needs to be divisible by c, c needs to be divisible by lcm, so gcd needs to be divisible by lcm ... else make new partition
int solution(vector<ll>& a, vector<ll>& b) {
    int res = 1;
    ll lcm = b[0];
    ll gcdiv = a[0] * b[0];
    for (int i=1; i<N; ++i) {
        lcm = (lcm * b[i]) / gcd(lcm, b[i]);
        gcdiv = gcd(gcdiv, a[i] * b[i]);
        if (gcdiv % lcm) {
            ++res;
            lcm = b[i];
            gcdiv = a[i] * b[i];
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<ll> a(N);
        vector<ll> b(N);
        for (int j=0; j<N; ++j) {
            cin >> a[j] >> b[j];
        }
        res[i] = solution(a, b);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}