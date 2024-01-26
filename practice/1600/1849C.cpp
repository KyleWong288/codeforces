#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;

int N, M;

// split is a pair: an index and the number of 0s to the left of that index
// each sorted subarray has a split between 0 and 1s, use split to uniquely identify strings
// filter out subarrays that are already sorted to guarantee we have a split
int solution(string& s, vector<pair<int,int>>& v) {
    int res = 0;
    vector<int> pref(N+1, 0);
    for (int i=0; i<N; ++i) {
        pref[i+1] = pref[i];
        if (s[i] == '0') {
            ++pref[i+1];
        }
    }
    // filter out sorted
    vector<bool> isSorted(M, 0);
    for (int i=0; i<M; ++i) {
        int l = v[i].first - 1;
        int r = v[i].second;
        int cntZ = pref[r] - pref[l];
        if (pref[l + cntZ] == pref[r]) {
            isSorted[i] = 1;
            res = 1;
        }
    }
    // find # of unique splits
    set<pair<int,int>> splits;
    for (int i=0; i<M; ++i) {
        if (isSorted[i]) {
            continue;
        }
        int l = v[i].first - 1;
        int r = v[i].second;
        int cntZ = pref[r] - pref[l];
        splits.insert({l + cntZ, pref[l] + cntZ});
    }
    res += splits.size();
    return res;
}

int main() {
    int T;
    cin >> T;
    string s;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M >> s;
        vector<pair<int,int>> v(M);
        for (auto& pr : v) {
            cin >> pr.first >> pr.second;
        }
        res[i] = solution(s, v);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}