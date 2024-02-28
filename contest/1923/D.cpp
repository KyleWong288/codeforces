#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// for each a[i], find some range either [unk, i-1] or [i+1, unk] such that range sum > a[i]
// # of moves is just the length of the range eaten
// when does a range not work? we can always pick the max slime in the range as our eater
// thus, range fails when each max is surrounded by equal maxs, aka the entire range is uniform
// find unk with bs
void solve(vector<ll>& a) {
    vector<int> res(N);
    // ps[i] = sum from [0, i-1]
    vector<ll> ps(N+1);
    for (int i=0; i<N; ++i) {
        ps[i+1] = ps[i] + a[i];
    }
    // change[i] = closest index to the left with a different value than a[i]
    vector<ll> change(N);
    for (int i=0; i<N; ++i) {
        if (i > 0 && a[i] == a[i-1]) {
            change[i] = change[i-1];
        }
        else {
            change[i] = i-1;
        }
    }
    // bs:
    int l, r;
    for (int i=0; i<N; ++i) {
        // try left:
        int bestL = -1;
        l = 0;
        r = i-1;
        while (l <= r) {
            int m = (l + r) / 2;
            ll sum = ps[i] - ps[m];
            if (sum > a[i] && (change[i-1] != change[m])) {
                l = m+1;
                bestL = max(bestL, m);
            }
            else {
                r = m-1;
            }
        }
        // try right:
        int bestR = N+1;
        l = i+1;
        r = N-1;
        while (l <= r) {
            int m = (l + r) / 2;
            ll sum = ps[m+1] - ps[i+1];
            if (sum > a[i] && (change[i+1] != change[m])) {
                r = m-1;
                bestR = min(bestR, m);
            }
            else {
                l = m+1;
            }
        }
        // edge cases:
        if (i > 0 && a[i-1] > a[i]) bestL = i-1;
        if (i < N-1 && a[i+1] > a[i]) bestR = i+1;
        // get best between left and right:
        bestL = (bestL == -1 ? 1e9 : i - bestL);
        bestR = (bestR == N+1 ? 1e9 : bestR - i);
        res[i] = min(bestL, bestR);
        if (res[i] == 1e9) res[i] = -1;
    }
    for (auto& x : res) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        solve(a);
    }
    return 0;
}