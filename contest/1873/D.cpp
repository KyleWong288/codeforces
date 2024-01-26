#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N, K;

int solution(string& s) {
    int res = 0;
    int l = 0;
    int r = 0;
    while (l < s.size()) {
        while (l < s.size() && s[l] != 'B') {
            ++l;
        }
        if (l >= s.size()) {
            break;
        }
        int take = K-1;
        r = l;
        while (take-- && r < s.size()) {
            ++r;
        }
        ++res;
        l = r+1;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    string s;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K >> s;
        res[i] = solution(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}