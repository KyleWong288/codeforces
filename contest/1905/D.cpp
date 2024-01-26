#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// classic compute base score and O(1) updates, think of a convenient starting point and order
// base score starts at 0 at right, iteratively move 0 left
// mono inc stack approach: stores <val, number of indices with this val>, when we pop we add the number of indices
ll solution(vector<int>& a) {
    ll res = N;
    // get base vector with 0 at right:
    int idx0 = min_element(a.begin(), a.end()) - a.begin();
    // compute updates:
    // stores <val, # of indicies with this val>
    ll score = N;
    vector<pair<ll,ll>> stack;
    for (int i=1; i<N; ++i) {
        int idx = (idx0 + i) % N;
        ll val = a[idx];
        ll len = 1;
        while (stack.size() && stack.back().first > val) {
            ll v = stack.back().first;
            ll l = stack.back().second;
            len += l;
            score -= (v * l);
            stack.pop_back();
        }
        stack.push_back({val, len});
        score += (val * len);
        res = max(res, score);
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