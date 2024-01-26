#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <numeric>
using namespace std;
typedef long long ll;

// naive: download -> watch -> delete singletons, this score is sum(a) + n
// save time by downloading another vid during the 1 second watch period
// since we insta-delete downloads, we always have at most 2 downloads
// thus, find max len sequence s.t each adjacent pair of indicies <= m: greedily pair (large, small)
ll solution(vector<ll>& a, int n, int m) {
    sort(a.begin(), a.end());
    ll chainable = 0;
    int l = 0;
    int r = n-1;
    while (l <= r) {
        while (l < r && a[l] + a[r] > m) {
            --r;
        }
        // see if we can chain the last l val
        if (l == r) {
            if (l > 0 && a[l-1] + a[l] <= m) {
                chainable += 1;
            }
            break;
        }
        chainable += 2;
        ++l;
        --r;
    }
    ll res = accumulate(a.begin(), a.end(), 0LL) + n;
    if (chainable) {
        res -= (chainable - 1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    cout << solution(a, n, m) << endl;
    return 0;
}