#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <numeric>
using namespace std;
typedef long long ll;

// lcm(a, b) has lowest chance of having another multiple larger than a
// edge case 1: a = 1, ans = b^2
// edge case 2: lcm(a, b) = b, so multiply by (b/a) since a * (b/a) = b
ll solution(ll a, ll b) {
    if (a == 1) {
        return b * b;
    }
    ll g = gcd(a, b);
    ll lcm = (a * b) / g;
    if (lcm == b)  {
        return lcm * (b/a);
    }
    return lcm;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    ll a, b;
    for (int i=0; i<T; ++i) {
        cin >> a >> b;
        res[i] = solution(a, b);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}