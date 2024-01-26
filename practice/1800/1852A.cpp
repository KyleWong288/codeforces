#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, K;

// trivial case if v[0] isn't 1, we keep the smallest element (1)
// take your current number line, each element x shifts left by the # of takes to the left of x
// loop through K, each iteration your smallest number jumps by the prefix (update synchronously if you jump past takes)
ll solution(vector<ll>& v) {
    ll res = 1;
    if (v[0] != 1) {
        return res;
    }
    ll pref = 0;
    int idx = 0;
    for (int i=0; i<K; ++i) {
        res += pref;
        while (idx < N && v[idx] <= res) {
            ++idx;
            ++pref;
            ++res;
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
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