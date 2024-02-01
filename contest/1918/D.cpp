#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

int N;

// on idx r, r is used as block so doesn't contribute to sum
// window range is leftmost l s.t sum[l, r-1] <= goal
// blocks to use are in [l-1, r-1]
bool good(vector<int>& a, ll goal) {
    for (int i=1; i<=N; ++i) {
        if (a[i] > goal) return 0;
    }
    // dp[i] = min cost where i is a block and resultant subarrs from [0:i] are valid
    vector<ll> dp(N+1, 0);
    ll curSum = 0;
    int l = 1;
    // stores <dp val in window, freq>
    map<ll, int> freq;
    for (int r=1; r<=N; ++r) {
        while (curSum > goal) {
            freq[dp[l]]--;
            if (freq[dp[l]] == 0) {
                freq.erase(dp[l]);
            }
            curSum -= a[l++];
        }
        // min in window [l,r-1], as well as l-1
        ll low = dp[l-1];
        if (freq.size()) low = min(low, freq.begin()->first);
        dp[r] = low + a[r];
        freq[dp[r]]++;
        curSum += a[r];
    }
    curSum = 0;
    for (int i=N; i>=0; --i) {
        if (dp[i] <= goal && curSum <= goal) {
            return 1;
        }
        curSum += a[i];
    }
    return 0;
}

// min the max, obvious bs, guess k
// whats the for loop? greedy (append to cur array, if i overflows use i as a block and start new array) doesn't work, so that leaves dp
// dp[i] = min cost where i is a block and resultant subarrays from [0:i] are valid
// look at j in range, find the min dp[j], this can be done with sliding window since mono moves right
// treat each i as the last block -> if there exists i s.t dp[i] <= k and suff[i+1:n-1] <= k, k works
// dp only need to verify it works, not minimize!!
ll solve(vector<int>& a) {
    ll low = 0;
    ll high = 1e14;
    while (low <= high) {
        ll m = (low + high) / 2;
        bool g = good(a, m);
        if (g) {
            high = m-1;
        }
        else {
            low = m+1;
        }
    }
    return low;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> a(N+1);
        for (int i=1; i<=N; ++i) {
            cin >> a[i];
        }
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}