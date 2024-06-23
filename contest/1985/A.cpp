#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

void solve(string& s, string& t) {
    char ch = s[0];
    s[0] = t[0];
    t[0] = ch;
    cout << s << " " << t << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s, t;
    while (T--) {
        cin >> s >> t;
        solve(s, t);
    }
    return 0;
}