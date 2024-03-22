#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

bool isVowel(char c) {
    return (c == 'a' || c == 'e');
}

string solution(string& s) {
    // dp[i] = valid ending on index i of s[0:i], but dp is 1 indexed
    vector<bool> dp(N+1, 0);
    // par[i] = parent of i
    vector<int> par(N+1, -1);
    for (int i=0; i<N; ++i) {
        if (isVowel(s[i])) {
            if (i >= 1 && !isVowel(s[i-1])) {
                dp[i+1] = dp[i-1];
                par[i+1] = i-1;
            }
        }
        else {
            if (i >= 2 && isVowel(s[i-1]) && !isVowel(s[i-2])) {
                dp[i+1] = dp[i-2];
                par[i+1] = i-2;
            }
        }
    }
    string res = "";
    int cur = N;
    while (cur != 0) {
        int prev = par[cur];
        while (cur > prev) {
            res += s[--cur];
        }
        res += '.';
    }
    res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<string> res(T);
    string s;
    for (int i=0; i<T; ++i) {
        cin >> N >> s;
        res[i] = solution(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}