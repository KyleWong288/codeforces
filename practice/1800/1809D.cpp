#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <climits>
using namespace std;
typedef long long ll;

// try every pivot p where the string switches from 0s to 1s, track # of 1s to left and # of 0s to right
// we can do 1 swap, where v[i] = 1 and v[i+1] = 0, better than a deletion
ll solution(string& s) {
    int N = s.size();
    ll res = LLONG_MAX;
    ll SWAP = 1000000000000;
    ll DEL = 1000000000001;
    vector<ll> left1s(N, 0);
    for (int i=0; i<N; ++i) {
        if (s[i] == '1') {
            left1s[i]++;
        }
        if (i) { 
            left1s[i] += left1s[i-1];
        }
    }
    vector<ll> right0s(N, 0);
    for (int i=N-1; i>=0; --i) {
        if (s[i] == '0') {
            right0s[i]++;
        }
        if (i < N-1) {
            right0s[i] += right0s[i+1];
        }
    }
    for (int i=0; i<N; ++i) {
        ll cost = 0;
        if (i < N-1 && s[i] == '1' && s[i+1] == '0') {
            cost += SWAP;
            if (i > 0) {
                cost += left1s[i-1] * DEL;
            }
            if (i < N-2) {
                cost += right0s[i+2] * DEL;
            }
        }
        else {
            if (i > 0) {
                cost += left1s[i-1] * DEL;
            }
            if (i < N-1) {
                cost += right0s[i+1] * DEL;
            }
        }
        res = min(res, cost);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> s;
        res[i] = solution(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}