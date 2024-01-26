#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

// for each a[r], find the optimal a[l], where optimal subarrays always have a[l] == a[r]
// we want to maximize count(a[r]) - count(not a[r]), get this prefix diff at each index
// on index r, lookup the optimal left end point (minimal diff for that same value)
void solution(vector<int>& a, int n) {
    int bestDiff = 0;
    int resA = 0;
    int resL = 0;
    int resR = 0;
    map<int,int> freq;
    // maps <val, min {count val - count non val} found>
    map<int, pair<int,int>> lefts;
    for (int i=0; i<n; ++i) {
        int f = ++freq[a[i]];
        int diff = f - (i + 1 - f);
        if (lefts.find(a[i]) == lefts.end()) {
            lefts[a[i]] = {f, i + 1 - f};
        }
        else {
            int oldDiff = lefts[a[i]].first - lefts[a[i]].second;
            if (diff < oldDiff) {
                lefts[a[i]] = {f, i + 1 - f};
            }
        }
        diff = (f - lefts[a[i]].first + 1) - (i + 1 - f - lefts[a[i]].second);
        if (diff > bestDiff) {
            resA = a[i];
            resL = lefts[a[i]].first + lefts[a[i]].second - 1;
            resR = i;
            bestDiff = diff;
        }
    }
    cout << resA << " " << resL+1 << " " << resR+1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, N;
    cin >> T;
    while(T--) {
        cin >> N;
        vector<int> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        solution(a, N);
    }
    return 0;
}