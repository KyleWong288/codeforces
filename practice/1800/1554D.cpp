#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// (even len spam) (single char) (even len spam)
// the count of all substrings formed by the two even len spams is even, since its 2 * (some number)
// (even len spam) (single char) (even len - 1 spam) turns the counts odd, since we lose 1 of each substring
void solution(int n) {
    string s;
    if (n == 1) {
        s = "a";
    }
    else if (n % 2) {
        int half = n/2;
        for (int i=0; i<half; ++i) {
            s += 'a';
        }
        s += 'b';
        for (int i=0; i<half-1; ++i) {
            s += 'a';
        }
        s += 'c';
    }
    else {
        int half = n/2;
        for (int i=0; i<half; ++i) {
            s += 'a';
        }
        s += 'b';
        for (int i=0; i<half-1; ++i) {
            s += 'a';
        }
    }
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int n;
    while (T--) {
        cin >> n;
        solution(n);
    }
    return 0;
}