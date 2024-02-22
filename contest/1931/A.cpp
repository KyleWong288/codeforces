#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

void solve(int n) {
    string res = "";
    for (int i=0; i<26; ++i) {
        for (int j=0; j<26; ++j) {
            for (int k=0; k<26; ++k) {
                if (i + j + k == n - 3) {
                    res += 'a'+i;
                    res += 'a'+j;
                    res += 'a'+k;
                    cout << res << endl;
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int n;
    while (T--) {
        cin >> n;
        solve(n);
    }
    return 0;
}