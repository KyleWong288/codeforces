#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// if we fill a segment of len >= 3, we can spam from the middle and no more ops
// else, we need to do singleton ops
int solution(string& s, int n) {
    for (int i=0; i<n-2; ++i) {
        if (s[i] == '.' && s[i+1] == '.' && s[i+2] == '.') {
            return 2;
        }
    }
    int res = 0;
    for (auto& ch : s) {
        if (ch == '.') {
            ++res;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, N;
    cin >> T;
    string s;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> s;
        res[i] = solution(s, N);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}