#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

int solution(string& s, string& t) {
    int need1 = 0;
    int need0 = 0;
    for (int i=0; i<N; ++i) {
        if (s[i] != t[i]) {
            if (s[i] == '0') {
                ++need1;
            }
            else {
                ++need0;
            }
        }
    }
    int res = min(need1, need0);
    res += max(need1, need0) - min(need1, need0);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    string s, t;
    for (int i=0; i<T; ++i) {
        cin >> N >> s >> t;
        res[i] = solution(s, t);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}