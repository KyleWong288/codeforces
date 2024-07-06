#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

ll N, K;

// fails is k is odd (even/odd swap adds 2 indices with diff parities)
// fails if k is too large (more than reverse permutation distance)
// most aggressive strategy: greedily build reverse permutation, maybe one special swap at end (i can make any smaller even #)
void solve() {
    if (K % 2) {
        cout << "NO" << endl;
        return;
    }
    ll most = 0;
    for (int i=0; i<N/2; ++i) {
        int l = i+1;
        int r = N-i;
        most += (r - l) * 2;
    }
    if (K > most) {
        cout << "NO" << endl;
        return;
    }
    // construct
    vector<int> perm(N, 0);
    for (int i=0; i<N; ++i) {
        perm[i] = i+1;
    }
    int l = 0;
    int r = N-1;
    while (K > 0) {
        ll diff = (perm[r] - perm[l]) * 2;
        // normal greedy build reverse
        if (diff <= K) {
            swap(perm[l], perm[r]);
            ++l;
            --r;
            K -= diff;
        }
        // special case at end
        else {
            while ((perm[r] - perm[l]) * 2 > K) {
                --r;
            }
            swap(perm[l], perm[r]);
            K = 0;
        }
    }
    cout << "YES" << endl;
    for (auto& x : perm) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        solve();
    }
    return 0;
}