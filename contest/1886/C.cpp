#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// monostack since the left most deletion has highest lexical impact 
char solution(string& s, ll pos) {
    int i = 0;
    string build = "";
    while (i < s.size() && (build.empty() || build.back() <= s[i])) {
        build += s[i++];
    }
    int len = s.size();
    while (pos > len) {
        build.pop_back();
        while (i < s.size() && (build.empty() || build.back() <= s[i])) {
            build += s[i++];
        }
        pos -= len;
        len--;
    }
    while (i < s.size()) {
        build += s[i++];
    }
    return build[pos-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    ll pos;
    string s;
    vector<char> res(T);
    for (int i=0; i<T; ++i) {
        cin >> s >> pos;
        res[i] = solution(s, pos);
    }
    for (auto& r : res) {
        cout << r;
    }
    cout << endl;
    return 0;
}