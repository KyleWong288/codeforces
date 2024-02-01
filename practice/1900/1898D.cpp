#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;

int N;

// treat abs like intervals, only non overlapping intervals can benefit
// swapping b[i] and b[j] adds 2 * a[j] - b[i] to the original score
// so greedily best swap is pair with earliest b[i] and pair with latest a[j]
ll solve(vector<int>& a, vector<int>& b) {
    ll res = 0;
    int earlyB = 2e9;
    int lateA = -2e9;
    for (int i=0; i<N; ++i) {
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
        }
        res += b[i] - a[i];
        earlyB = min(earlyB, b[i]);
        lateA = max(lateA, a[i]);
    }
    ll newRes = res + 2LL * (lateA - earlyB);
    res = max(res, newRes);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> a(N);
        vector<int> b(N);
        for (auto& x : a) {
            cin >> x;
        }
        for (auto& x : b) {
            cin >> x;
        }
        res[i] = solve(a, b);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}