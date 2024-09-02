#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
using namespace std;
typedef long long ll;

int solve(int x) {
    string s = to_string(x);
    if (s.size() <= 2) return 0;
    if (s[0] != '1' || s[1] != '0') return 0;
    if (s[2] == '0') return 0;
    if (x == 101) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int x;
    while (T--) {
        cin >> x;
        if (solve(x)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}