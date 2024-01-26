#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// 2 stacks
void solution(string& s) {
    string res = "";
    // store idxs
    vector<int> low;
    vector<int> up;
    for (int i=0; i<s.size(); ++i) {
        char ch = s[i];
        if (ch == 'b') {
            if (low.size()) {
                low.pop_back();
            }
        }
        else if (ch == 'B') {
            if (up.size()) {
                up.pop_back();
            }
        }
        else if (ch <= 'Z') {
            up.push_back(i);
        }
        else {
            low.push_back(i);
        }
    }
    for (auto& x : up) {
        low.push_back(x);
    }
    sort(low.begin(), low.end());
    for (auto& x : low) {
        res += s[x];
    }
    cout << res << endl;
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