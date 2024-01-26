#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// always better to accumulate combo with small and release on big, rather than vice versa
// sort and 2 ptrs: accumulate combo with l, release combo on r
ll solution(vector<ll>& a) {
    if (a.size() == 1) {
        if (a[0] == 1) {
            return 1;
        }
        else {
            return (a[0] + 1) / 2 + 1;
        }
    }
    ll res = 0;
    ll combo = 0;
    sort(a.begin(), a.end());
    int l = 0;
    int r = N-1;
    while (l <= r) {
        if (l == r) {
            if (combo >= a[l]) {
                ++res;
            }
            else if (a[l] == 1) {
                ++res;
            }
            else {
                res += (a[l] - combo + 1) / 2;
                ++res;
            }
            ++l;
        }
        else {
            int take = min(a[l], a[r] - combo);
            a[l] -= take;
            combo += take;
            res += take;
            if (a[l] == 0) { // move left
                ++l;
            }
            if (combo == a[r]) { // move right
                combo = 0;
                a[r--] = 0;
                ++res;
            }
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