#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;
 
int N;
 
// we can slide 1 left if we have 0010 and slide 1 right if we have 0100
// we can generate any subarray of 1s from a single 1
// we can never go from 010 to 000 (can't kill 1s)
// fail: s has more subarrays of 1s, since we can't merge 2 subarrays of 2s (101)
// greedily match ith subarray of s with ith subarray of t
ll solution(string& s, string& t) {
    ll res = 0;
    // stores inclusive bounds of subarrays of 1s
    vector<pair<int,int>> subsS;
    vector<pair<int,int>> subsT;
    for (int l=0; l<N; ++l) {
        if (s[l] == '0') { continue; }
        int r = l;
        while (r < N && s[r] == '1') {
            ++r;
        }
        subsS.push_back({l, r-1});
        l = r-1;
    }
    for (int l=0; l<N; ++l) {
        if (t[l] == '0') { continue; }
        int r = l;
        while (r < N && t[r] == '1') {
            ++r;
        }
        subsT.push_back({l, r-1});
        l = r-1;
    }
    if (subsS.size() != subsT.size() || s[0] != t[0] || s[N-1] != t[N-1]) {
        return -1;
    }
    for (int i=0; i<subsS.size(); ++i) {
        int delL = abs(subsS[i].first - subsT[i].first);
        int delR = abs(subsS[i].second - subsT[i].second);
        res += delL + delR;
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s, t;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> s >> t;
        res[i] = solution(s, t);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}