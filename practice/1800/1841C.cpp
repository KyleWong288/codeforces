#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;
typedef long long ll;

unordered_map<char, int> val;

ll score(string& s) {
    ll res = 0;
    char high = '0';
    for (int i=s.size()-1; i>=0; --i) {
        if (s[i] >= high) {
            high = s[i];
            res += val[high];
        }
        else {
            res -= val[s[i]];
        }
    }
    return res;
}

// compute base score with no changes, 2 ways to maximize score:
// 1. change the first occurrence of each char into anything higher
// 2. change the last occurrence of each char into anything lower
ll solution(string& s) {
    ll res = score(s);
    // change to higher
    vector<bool> found(5, 0);
    found[4] = 1;
    for (int i=0; i<s.size(); ++i) {
        int ch = s[i] - 'A';
        if (!found[ch]) {
            string t = s;
            for (int c=ch; c<5; ++c) {
                t[i] = 'A' + c;
                res = max(res, score(t));
            }
            found[ch] = 1;
        }
    }
    // change to lower
    found = {0,0,0,0,0};
    found[0] = 1;
    for (int i=s.size()-1; i>=0; --i) {
        int ch = s[i] - 'A';
        if (!found[ch]) {
            string t = s;
            for (int c=0; c<ch; ++c) {
                t[i] = 'A' + c;
                res = max(res, score(t));
            }
            found[ch] = 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    vector<ll> res(T);
    val['A'] = 1;
    val['B'] = 10;
    val['C'] = 100;
    val['D'] = 1000;
    val['E'] = 10000;
    for (int i=0; i<T; ++i) {
        cin >> s;
        res[i] = solution(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}