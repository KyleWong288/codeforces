#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <climits>
using namespace std;
typedef long long ll;

int N;

// make a mono array via prefix/suffix subtractions, then we need abs(largest neg) additions to make everything >= 0, then we need largest pos subtractions to make everything = 0
// case 1: simulate mono-non-dec array, track prefix subtractions, largest pos on right
// case 2: simulate mono-non-inc array, track suffix subtractions, largest pos on left
ll solution(vector<ll>& v) {
    ll res = LLONG_MAX;
    // simulate mono-non-dec:
    ll leftOps = 0;
    for (int i=0; i<N-1; ++i) {
        if (v[i+1] < v[i]) {
            leftOps += v[i] - v[i+1];
        }
    }
    ll low = v[0] - leftOps;
    ll rightVal = v[N-1];
    if (low < 0) {
        // need to add up to 0 -> additional neg additions and neg subtractions
        res = min(res, leftOps - 2 * low + rightVal);
    }
    else {
        res = min(res, leftOps + rightVal);
    }
    // simulate mono-non-inc:
    ll rightOps = 0;
    for (int i=N-1; i>0; --i) {
        if (v[i-1] < v[i]) {
            rightOps += v[i] - v[i-1];
        }
    }
    low = v[N-1] - rightOps;
    ll leftVal = v[0];
    if (low < 0) {
        res = min(res, rightOps - 2 * low + leftVal);
    }
    else {
        res = min(res, rightOps + leftVal);
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