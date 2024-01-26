#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

bool canMatch(vector<ll>& a, ll ones, ll twos, ll goal) {
    for (auto& x : a) {
        ll diff = goal - x;
        // using 2:
        ll use2 = min(twos, diff / 2);
        diff -= use2 * 2;
        twos -= use2;
        // using 1:
        ones -= diff;
    }
    return (ones >= 0);
}

// your highest should either be max height h or h+1, solve independently
// h+1 should be considered since [h-1,h-1,... h] has lots of idle time, if the values are h-2 or less, there isn't any idle time
// bs on how many operations to use
// spam 2s when you can since these are harder to place, use 1s sparingly or when run out of 2s
ll solution(vector<ll>& a) {
    ll res = 1e18;
    ll goal = *max_element(a.begin(), a.end());
    bool good;
    // solve for h:
    ll l = 0, r = 1e18;
    while (l <= r) {
        ll m = (l + r) / 2;
        good = canMatch(a, (m+1)/2, m/2, goal);
        if (good) {
            r = m-1;
        }
        else {
            l = m+1;
        }
    }
    res = l;
    // solve for h+1:
    l = 0, r = 1e18;
    while (l <= r) {
        ll m = (l + r) / 2;
        good = canMatch(a, (m+1)/2, m/2, goal+1);
        if (good) {
            r = m-1;
        }
        else {
            l = m+1;
        }
    }
    res = min(res, l);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solution(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}