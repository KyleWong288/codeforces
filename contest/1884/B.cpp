#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// divisible by 2^i means you have no 1 bits after the ith bit
// two ptrs, track the current bit and track the next open 0 bit to the left
// if the current bit is one, do a swap (by incrementally moving the 0 rightwards) and move the 0 bit ptr
void solution(int n, string& s) {
    // edge case for 0:
    int cnt = 0;
    for (auto& ch : s) cnt += (ch == '1');
    if (cnt == 0) {
        for (int i=1; i<=n; ++i) {
            cout << 0 << " ";
        }
        cout << endl;
        return;
    }
    // regular:
    vector<ll> res(n+1, -1);
    res[0] = 0;
    reverse(s.begin(), s.end());
    int r = 0;
    for (int l=0; l<n; ++l) {
        r = max(l,r);
        while (r < n && s[r] == '1') {
            ++r;
        }
        if (r >= n) { break; }
        ll diff = 0;
        if (s[l] == '1') {
            diff = r - l;
            s[r++] = '1';
        }
        res[l+1] = res[l] + diff;
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
    int n;
    string s;
    while (T--) {
        cin >> n >> s;
        solution(n, s);
    }
    return 0;
}