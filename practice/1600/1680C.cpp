#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

// output space is between (# of 0s, 0) and (0, # of 1s)
// binary search on the # of 0s to keep: if # of 0s to keep < # of 1s to delete, keep more 0s
// use a sliding window to get all substrings with desired # of 0s
int solution(string& s) {
    int n = s.size();
    // prefix array to count 1s:
    vector<int> pref(n+1, 0);
    for (int i=0; i<n; ++i) {
        pref[i+1] = pref[i] + (s[i] == '1');
    }
    // binary search on # of 0s:
    int l = 0;
    int r = 0;
    for (auto& c : s) {
        r += (c == '0');
    }
    int res = r;
    while (l <= r) {
        int m = (l + r) / 2;
        int cnt = 0, p1 = 0, p2 = 0, best = 1e9;
        for (p1=0; p1<n; ++p1) {
            while (p2 < n && (cnt <= m || s[p2] == '0')) {
                cnt += (s[p2++] == '0');
            }
            int onesL = pref[p1] - pref[0];
            int onesR = pref[n] - pref[p2];
            best = min(best, onesL + onesR);
            cnt -= (s[p1] == '0');
        }
        res = min(res, max(m, best));
        if (m <= best) {
            l = m+1;
        }
        else {
            r = m-1;
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    string s;
    for (int i=0; i<T; ++i) {
        cin >> s;
        res[i] = solution(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}