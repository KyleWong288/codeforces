#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// A's cascade to the right
// evaluate r->l by tracking consecutive Bs
ll solution(string& s) {
    ll res = 0;
    ll consecB = 0;
    for (int i=N-1; i>=0; --i) {
        if (s[i] == 'A') {
            res += consecB;
            if (consecB > 0) {
                consecB = 1;
            }
        }
        else {
            ++consecB;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> s;
        res[i] = solution(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}