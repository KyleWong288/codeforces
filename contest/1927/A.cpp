#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

int solve(string& s) {
    int l = -1;
    int r = -1;
    for (int i=0; i<N; ++i) {
        if (s[i] == 'B') {
            if (l == -1) {
                l = i;
            }
            r = i;
        }
    }
    int res = r - l + 1;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    string s;
    for (int i=0; i<T; ++i) {
        cin >> N >> s;
        res[i] = solve(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}