#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

bool worksMin(vector<ll>& a, ll low) {
    ll excess = 0;
    for (auto& x : a) {
        if (x > low) excess += x - low;
        else excess -= low - x;
        if (excess < 0) return 0;
    }
    return 1;
}

bool worksMax(vector<ll>& a, ll high) {
    ll excess = 0;
    for (auto& x : a) {
        if (x > high) excess += x - high;
        else excess -= min(high - x, excess);
    }
    return excess == 0;
}

// hard to bs on two moving endpoints, so find one, then find other
// min value in optimal array is the highest min value possible, think proof by contradiction
// bs for max min value -> construct the most left aligned array -> bs for min max value
ll solve(vector<ll>& a) {
    // bs for max min value
    ll l = 0, r = 1e12;
    while (l <= r) {
        ll m =(l + r) / 2;
        if (worksMin(a, m)) l = m + 1;
        else r = m - 1;
    }
    ll low = r;
    // construct most left aligned array
    // stores indices with excess
    vector<int> excess;
    for (int i=0; i<N; ++i) {
        if (a[i] > low) excess.push_back(i);
        while (a[i] < low) {
            int j = excess.back();
            ll use = min(low - a[i], a[j] - low);
            a[i] += use;
            a[j] -= use;
            if (a[j] == low) excess.pop_back();
        }
    }
    // bs for min max value
    l = 0, r = 1e12;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (worksMax(a, m)) r = m - 1;
        else l = m + 1;
    }
    ll high = l;
    return high - low;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<ll> a(N);
        for (auto& x : a) cin >> x;
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}