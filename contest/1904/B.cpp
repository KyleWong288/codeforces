#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

int N;

// sort and prefix sum, if a[i] > pref[0,i-1] it blocks
// each index needs to know the closest block after
void solution(vector<pair<int,int>>& a) {
    vector<ll> res(N);
    sort(a.begin(), a.end());
    // stores <value, index>
    set<pair<ll,ll>> blocks;
    vector<ll> pref(N+1, 0);
    for (int i=0; i<N; ++i) {
        pref[i+1] = pref[i] + a[i].first;
        if (a[i].first > pref[i] && i != 0) {
            blocks.insert({a[i].first, i});
        }
    }
    for (int i=0; i<N; ++i) {
        pair<ll,ll> target = {pref[i+1], 0};
        int idx = a[i].second;
        auto it = blocks.upper_bound(target);
        if (it == blocks.end()) {
            res[idx] = N-1;
        }
        else {
            ll end = it->second;
            res[idx] = end - 1;
        }
    }
    for (auto& r : res) {
        cout << r << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<pair<int,int>> a(N);
        for (int i=0; i<N; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        solution(a);
    }
    return 0;
}