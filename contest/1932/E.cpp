#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int n;

// string addition skull!!??
// 12345: digit 1 changes 1 time, digit 2 changes 12 times, digit 3 changes 123 times...
// many additions are slow, how can we solve it in 1 addition?
// Add is like below. We can reuse our digit sum, just subtract the current digit and track the carry
// 12345
//  1234
//   123
//    12
//     1
void solve(string& s) {
    int sum = 0;
    int carry = 0;
    for (auto& ch : s) {
        sum += (ch - '0');
    }
    string res = "";
    for (int i=n-1; i>=0; --i) {
        int newSum = sum + carry;
        int digit = newSum % 10;
        int digitInS = s[i] - '0';
        res += '0' + digit;
        carry = newSum / 10;
        sum -= digitInS;
    }
    if (carry > 0) {
        while (carry) {
            int digit = carry % 10;
            res += '0' + digit;
            carry /= 10;
        }
    }
    while (res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    while (T--) {
        cin >> n >> s;
        solve(s);
    }
    return 0;
}