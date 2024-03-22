#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

ll N, P;

// greedily choose people with lower cost, replace any costs higher than p with p
ll solution(vector<ll>& a, vector<ll>& b) {
    // stores <cost, # of ppl to spread>
    vector<pair<ll,ll>> v(N);
    for (int i=0; i<N; ++i) {
        v[i] = {b[i], a[i]};
    }
    sort(v.begin(), v.end());
    // initialize res and cnt this way since Pak Chanek needs to tell at least 1 person
    ll res = P;
    ll cnt = 1;
    for (auto& pr : v) {
        if (pr.first >= P) { break; }
        ll use = min(N - cnt, pr.second);
        cnt += use;
        res += use * pr.first;
    }
    res += P * (N - cnt);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> P;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        vector<ll> b(N);
        for (auto& x : b) {
            cin >> x;
        }
        res[i] = solution(a, b);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}