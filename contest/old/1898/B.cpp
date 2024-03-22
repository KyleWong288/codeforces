#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// numbers only get smaller so last val is bottleneck, always best to divide as evenly as possible
// track running min r -> l; if min = M and # of groups = x, then a[i] / x <= M -> ceil(a[i] / M) = x
// update min: since x is optimal # of groups, new min is a[i] / x
ll solution(vector<ll>& a) {
    ll res = 0;
    ll low = a[N-1];
    for (ll i=N-2; i>=0; --i) {
        if (a[i] <= low) { 
            low = a[i];
            continue;
        }
        ll groups = (a[i] + low - 1) / low;
        low = a[i] / groups;
        res += groups-1;
    }
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