#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// consecutive pos fails -> array should be pos spaced with some amount of negatives in between
// higher subarray sum is more notable, thus we want the mss ending at each pos
// when we find a new pos, try and append to the mss at the previous pos
int solution(vector<ll>& a) {
    ll pmax = -2e9;
    ll sum = 0;
    for (int i=0; i<N; ++i) {
        ll newSum = max(a[i], sum + a[i]);
        if (newSum > sum) {
            sum = newSum;
            pmax = max(pmax, a[i]);
            if (pmax < sum) {
                return 0;
            }
        }
        else {
            sum = 0;
            pmax = -2e9;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solution(a);
    }
    for (auto& r : res) {
        cout << (r ? "YES\n" : "NO\n");
    }
    return 0;
}