#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, C;

// Greedily always link with 1: For i,j != 1, if a[i] + a[j] >= i * j, then a[i] >= i or a[j] >= j. Replace the lesser between a[i] and a[j] with a[1] and 1
// Optimal node taking: sort by (k * c - a[k]), since we want cumsum + a[k] >= 1 * k * c
int solution(vector<ll>& a) {
    vector<pair<ll,ll>> prs(N);
    for (ll i=2; i<=N; ++i) {
        prs[i-1] = {i * C - a[i], i};
    }
    sort(prs.begin(), prs.end());
    ll sum = a[1];
    for (auto& pr : prs) {
        ll idx = pr.second;
        if ((sum + a[idx]) >= idx * C) {
            sum += a[idx];
        }
        else {
            return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> C;
        vector<ll> a(N+1);
        for (int i=1; i<=N; ++i) {
            cin >> a[i];
        }
        res[i] = solution(a);
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