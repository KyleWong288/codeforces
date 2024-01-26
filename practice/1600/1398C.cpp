#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;
typedef long long ll;

int N;

// a good subarray is some (i, j) where i - j == pref[i] - pref[j]
// rearrange to get i - pref[i] = j - pref[j], so just keep a freqmap of j - pref[j]
ll solution(string& s) {
    ll res = 0;
    unordered_map<ll, ll> freq;
    ll psum = 0;
    for (int i=0; i<N; ++i) {
        int v = s[i] - '0';
        psum += v;
        res += freq[i - psum];
        // connects to beginning:
        if (i+1 == psum) {
            ++res;
        }
        freq[i - psum]++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> s;
        res[i] = solution(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}