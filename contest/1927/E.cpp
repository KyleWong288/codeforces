#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// pair (1,n), (2,n-1) ... -> sum of (s,e) is always n+1
// even k: [s,e,s,e,s,e] or [e,s,e,s,e,s]
// first case easy, second case, need to make sure first e + last s is n+2
// insert pairs in order, hopping every k steps
void solve(int n, int k) {
    vector<int> res(n+1);
    int l = 1;
    int r = n;
    int origin = 1;
    int cur = 1;
    while (l <= r) {
        res[cur] = l++;
        if (cur+1 <= n) res[cur+1] = r--;
        cur += k;
        if (cur > n) {
            origin += 2;
            cur = origin;
        }
    }
    for (int i=1; i<=n; ++i) {
        cout << res[i] << " ";
    }
    
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int N, K;
    while (T--) {
        cin >> N >> K;
        solve(N, K);
    }
    return 0;
}