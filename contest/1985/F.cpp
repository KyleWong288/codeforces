#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

ll H, N;

// how many rounds for a fixed time? ceiling
bool works(vector<vector<ll>>& attacks, ll time) {
    ll d = 0;
    for (auto& pr : attacks) {
        ll rounds = (time + pr[1] - 1) / pr[1];
        d += pr[0] * (rounds);
        if (d >= H) return 1;
    }
    return 0;
}

// bs the number of turns
ll solve(vector<vector<ll>>& attacks) {
    ll l = 1, r = 1e12;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (works(attacks, m)) {
            r = m-1;
        }
        else {
            l = m+1;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> H >> N;
        // stores <damage, time>
        vector<vector<ll>> attacks(N, vector<ll>(2));
        for (auto& x : attacks) {
            cin >> x[0];
        }
        for (auto& x : attacks) {
            cin >> x[1];
        }
        res[i] = solve(attacks);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}