#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;
const int MOD = 1e9+7;

// insert numbers into B in sorted order and track the minimal subarray that contains all numbers so far
// case 1: the cur number expands the subarray and must be placed at the same index as in A
// case 2: the cur number is inside the subarray, and can be placed anywhere in the subarray
// how to count? for case 2, use any possible spot: len of array - cur number + 1 
ll solution(vector<int>& a) {
    ll res = 1;
    // stores <val, idx in a>
    vector<pair<int,int>> prs(N);
    for (int i=0; i<N; ++i) {
        prs[i] = {a[i], i};
    }
    sort(prs.begin(), prs.end());
    int l = prs[0].second;
    int r = prs[0].second;
    for (int i=1; i<N; ++i) {
        int idx = prs[i].second;
        if (idx < l) {
            l = idx;
        }
        else if (idx > r) {
            r = idx;
        }
        else {
            ll spots = (r - l + 1) - i;
            res = res * spots % MOD;
        }
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
        vector<int> a(N);
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