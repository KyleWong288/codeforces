#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

int n, k, m;

// partition s, each part is minimal window where each char occurs >= 1
// at the end of each partition is always a char with freq 1
// append these guys to missing ssq since they have "the least after them" 
void solve(string& s) {
    int parts = 0;
    string miss = "";
    set<char> have;
    for (int l=0; l<m; ++l) {
        int r;
        for (r=l; r<m; ++r) {
            have.insert(s[r]);
            if (have.size() == k) {
                miss += s[r];
                break;
            }
        }
        if (have.size() < k) {
            break;
        }
        ++parts;
        l = r;
        have.clear();
    }
    if (parts >= n) {
        cout << "YES" << endl;
        return;
    }
    else {
        cout << "NO" << endl;
        for (int i=0; i<k; ++i) {
            char ch = 'a' + i;
            if (have.find(ch) == have.end()) {
                while (miss.size() < n) {
                    miss += ch;
                }
                break;
            }
        }
        cout << miss << endl;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    while (T--) {
        cin >> n >> k >> m >> s;
        solve(s);
    }
    return 0;
}