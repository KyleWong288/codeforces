#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

void solution(string& s) {
    for (int i=1; i<=8; ++i) {
        if (i != (s[1]-'0')) {
            string t = s;
            t[1] = ('0' + i);
            cout << t << endl;
        }
    }
    for (char i='a'; i<='h'; ++i) {
        if (i != s[0]) {
            string t = s;
            t[0] = i;
            cout << t << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    while (T--) {
        cin >> s;
        solution(s);
    }
    return 0;
}