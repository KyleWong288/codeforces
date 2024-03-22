#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <climits>
#include <cmath>
using namespace std;
typedef long long ll;

int N;

// brute force?
ll solution(vector<ll>& a) {
    ll res = LLONG_MIN;
    int end = sqrt(N);
    for (int i=1; i<=end; ++i) {
        if (N % i) { continue; }
        // divisor 1:
        int p1 = i;
        ll low = LLONG_MAX;
        ll high = LLONG_MIN;
        int j = 0;
        while(j < N) {
            ll box = 0;
            for (int k=0; k<p1; ++k) {
                box += a[j++];
            }
            low = min(low, box);
            high = max(high, box);
        }
        res = max(res, high - low);
        // divisor 2:
        int p2 = N / i;
        low = LLONG_MAX;
        high = LLONG_MIN;
        j = 0;
        while (j < N) {
            ll box = 0;
            for (int k=0; k<p2; ++k) {
                box += a[j++];
            }
            low = min(low, box);
            high = max(high, box);
        }
        res = max(res, high - low);
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