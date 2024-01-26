#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, K;

// brute force over all targets t, try to get each a[i] / p[i] as close to t as possible
// a[i] / p[i] = t, so the optimal p[i] is a[i] / t 
void solution(vector<int>& a) {
    int res = 1e9;
    int end = *max_element(a.begin(), a.end());
    for (int t=1; t<=end; ++t) {
        int low = 1e9;
        int high = -1e9;
        for (auto& x : a) {
            int p = x / t;
            p = min(K, max(p, 1));
            low = min(low, x / p);
            high = max(high, x / p);
        }
        res = min(res, high - low);
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<int> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        solution(a);
    }
    return 0;
}