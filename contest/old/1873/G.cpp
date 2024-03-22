#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

// A, A, ... B means B spreads left
// B, A, ... A means B spreads right
// break into subarrays of A and singleton Bs, sort As by len, for each B we take the biggest left
int solution(string& s) {
    int n = s.size();
    vector<int> lens;
    for (int i=0; i<s.size(); ++i) {
        while (i < s.size() && s[i] == 'B') {
            ++i;
        }
        int j = i;
        while (j < s.size() && s[j] == 'A') {
            ++j;
        }
        lens.push_back(j - i);
        i = j;
    }
    sort(lens.rbegin(), lens.rend());
    int cnt = 0;
    for (auto& c : s) {
        if (c == 'B') {
            ++cnt;
        }
    }
    int res = 0;
    int sz = lens.size();
    for (int i=0; i<min(cnt, sz); ++i) {
        res += lens[i];
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    string s;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> s;
        res[i] = solution(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}