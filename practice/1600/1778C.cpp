#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

ll N, K;

// backtracking approach to generate all sets of characters
void genChoices(vector<vector<bool>>& choices, vector<bool>& build, vector<bool>& have, int cnt, int sIdx) {
    if (cnt >= K) {
        choices.push_back(build);
        return;
    }
    for (int i=sIdx; i<26; ++i) {
        if (have[i]) {
            have[i] = 0;
            build[i] = 1;
            genChoices(choices, build, have, cnt+1, i+1);
            have[i] = 1;
            build[i] = 0;
        }
    }
}

// brute force over all (# of unique chars) choose k sets of characters
// counting substrings: partition a based on mismatched chars, let n = [l,r], add n choose 2 
ll solution(string& a, string& b) {
    vector<bool> have(26, 0);
    for (auto& c : a) {
        have[c-'a'] = 1;
    }
    int used = 0;
    for (auto h : have) {
        used += h;
    }
    // edge case where k is higher than the # of unique chars
    if (used <= K) {
        return N * (N+1) / 2;
    }
    vector<vector<bool>> choices;
    vector<bool> build(26, 0);
    genChoices(choices, build, have, 0, 0);
    ll res = 0;
    for (auto& set : choices) {
        ll cnt = 0;
        for (int i=0; i<N; ++i) {
            int j = i;
            while (j < N && (set[a[j]-'a'] || a[j] == b[j])) {
                ++j;
            }
            ll n = j - i;
            cnt += n * (n+1) / 2;
            i = j;
        }
        res = max(res, cnt);
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    string a, b;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K >> a >> b;
        res[i] = solution(a, b);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}