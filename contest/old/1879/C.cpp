#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
vector<ll> factorial;

// if we have n consecutive same chars, we need to delete n-1 of them and we have (n choose n-1 -> n) ways of doing so
// if we have m deletions, we can order them in m! ways
pair<ll,ll> solution(string& s) {
    ll minOps = 0;
    ll ssqs = 1;
    for (int i=0; i<s.size(); ++i) {
        int j = i;
        if (s[i] == '1') {
            while (j < s.size() && s[j] == '1') {
                ++j;
            }
            int remove = j - i - 1;
            minOps += remove;
            ssqs *= (remove+1);
            ssqs %= MOD;
        }
        else {
            while (j < s.size() && s[j] == '0') {
                ++j;
            }
            int remove = j - i - 1;
            minOps += remove;
            ssqs *= (remove+1);
            ssqs %= MOD;
        }
        i = j-1;
    }
    ssqs = (ssqs * factorial[minOps]) % MOD;
    return {minOps, ssqs};
}

int main() {
    int T;
    cin >> T;
    string s;
    // precompute factorial
    factorial.resize(2e5+1, 1);
    for (int i=2; i<=2e5; ++i) {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
    vector<pair<ll,ll>> res(T);
    for (int i=0; i<T; ++i) {
        cin >> s;
        res[i] = solution(s);
    }
    for (auto& r : res) {
        cout << r.first << " " << r.second << endl;
    }
    return 0;
}