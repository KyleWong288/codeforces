#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// fails: odd length or if we reach a state of all 0s/1s
// two pointers (l, r) and go out to in, if we have [0, 0] append 01, if we have [1, 1], prepend 01
void solution(string& s) {
    if (N % 2) {
        cout << -1 << endl;
        return;
    }
    vector<int> res;
    int l = 0;
    int r = N-1;
    while (l < r) {
        // cout << s << " " << l << " " << r << endl;
        if (s[l] == '0' && s[r] == '0') {
            res.push_back(r+1);
            s.insert(r+1, "01");
            ++l;
            ++r;
        }
        else if (s[l] == '1' && s[r] == '1') {
            res.push_back(l);
            s.insert(l, "01");
            ++l;
            ++r;
        }
        else {
            ++l;
            --r;
        }
        if (l >= r) { break; }
        // uniform check
        bool diff = false;
        for (int i=l; i<=r; ++i) {
            if (s[i] != s[l]) {
                diff = true;
            }
        }
        if (!diff) {
            cout << -1 << endl;
            return;
        }
    }
    cout << res.size() << endl;
    for (auto& r : res) {
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    for (int i=0; i<T; ++i) {
        cin >> N >> s;
        solution(s);
    }
    return 0;
}