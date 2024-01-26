#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
#include <numeric>
using namespace std;
typedef long long ll;

int N;

// we want remainders % m to be the same: r1 = x - p*m, r2 = y - q*m, r1 == r2, so x - y = m(p - q), so (x - y) % m == 0 
// it looks like we need to check all pairs % m == 0, but we only need to check adjacent diffs
// we want to see does there exist some m >= 2 that divides all our diffs? OBVIOUSLY GCD
int solution(vector<int>& a) {
    int res = 0;
    vector<int> divs;
    int end = sqrt(N);
    for (int i=1; i<=end; ++i) {
        if (N % i == 0) {
            divs.push_back(i);
            if (N/i != i) divs.push_back(N/i);
        }
    }
    for (auto& div : divs) {
        int g = 0;
        for (int i=div; i<N; ++i) {
            int diff = abs(a[i] - a[i-div]);
            if (diff != 0) {
                if (g == 0) {
                    g = diff;
                }
                else {
                    g = gcd(g, diff);
                }
            }
        }
        if (g != 1) {
            ++res;
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
        vector<int> a(N);
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