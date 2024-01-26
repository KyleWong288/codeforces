#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

ll N, S;

// split a[i] greedily and dp (two dp vectors since 2 ways to end on index i)
// if a[i] >= 2s, split into (s, a[i] - s)
// if a[i] < 2s, split into (a[i] - s, s) or (0, a[i])
ll solution(vector<ll>& a) {
    // stores greedy splits as (x, y)
    vector<pair<ll,ll>> v(N);
    for (int i=1; i<N-1; ++i) {
        if (a[i] <= S) {
            v[i] = {0, a[i]};
        }
        else if (a[i] <= 2*S) {
            v[i] = {a[i] - S, S};
        }
        else {
            v[i] = {S, a[i] - S};
        }
    }
    // dpX[i] = min score ending on the first val of the pair at i
    vector<ll> dpX(N);
    // dpY[i] = min score ending on the second val of the pair at i
    vector<ll> dpY(N);
    dpX[1] = a[0] * v[1].second;
    dpY[1] = a[0] * v[1].first;
    for (int i=2; i<N-1; ++i) {
        dpX[i] = min(dpX[i-1] + v[i-1].first * v[i].second, dpY[i-1] + v[i-1].second * v[i].second);
        dpY[i] = min(dpX[i-1] + v[i-1].first * v[i].first, dpY[i-1] + v[i-1].second * v[i].first);
    }
    ll res = min(dpX[N-2] + v[N-2].first * a[N-1], dpY[N-2] + v[N-2].second * a[N-1]);    
    return res;
}

int main() {
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> S;
        vector<ll> v(N);
        for (auto& x : v) {
            cin >> x;
        }
        res[i] = solution(v);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}