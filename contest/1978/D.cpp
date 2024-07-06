#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

ll N, C;

// if i is not the original winner, we must remove [0:i)
// once we steal the original winner, the current index is always the winner
// if prefix sum is enough, don't steal max. Otherwise steal max.
void solve(vector<ll>& a) {
    int maxIdx = max_element(a.begin(), a.end()) - a.begin();
    int maxVal = a[maxIdx];
    // build res
    vector<int> res(N, 0);
    ll psum = 0;
    for (int i=0; i<N; ++i) {
        // steal from max
        if (a[i] + psum < maxVal) {
            res[i] = i + 1;
        }
        // no steal, prefix only
        else {
            res[i] = i;
        }
        psum += a[i];
    }
    res[maxIdx] = 0;
    for (auto& x : res) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    while (T--) {
        cin >> N >> C;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        a[0] += C;
        solve(a);
    }
    return 0;
}