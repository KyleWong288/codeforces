#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

ll N, K;

// just maximize bob's score
// sorted order, alice takes odd idxs, bob takes even idxs
ll solve(vector<ll>& a) {
    ll sA = 0, sB = 0;
    sort(a.rbegin(), a.rend());
    for (int i=0; i<N; ++i) {
        if (i % 2) { // bib
            if (K > 0) {
                ll diff = a[i-1] - a[i];
                ll use = min(K, diff);
                a[i] += use;
                K -= use;
            }
            sB += a[i];
        }
        else { // alice
            sA += a[i];
        }
    }
    return sA - sB;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
        vector<ll> a(N);
        for (auto& x : a) cin >> x;
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}