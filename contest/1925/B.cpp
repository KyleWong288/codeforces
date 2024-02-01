#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// divisors d of n, then find max(d) such that n / d >= x
int solve(int n, int x) {
    vector<int> divs;
    for (int i=1; i*i<=n; ++i) {
        if (n % i == 0) {
            divs.push_back(i);
            divs.push_back(n/i);
        }
    }
    sort(divs.begin(), divs.end());
    int res = 0;
    for (auto& d : divs) {
        if (n / d >= x) {
            res = d;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int n, x;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> x;
        res[i] = solve(n, x);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}