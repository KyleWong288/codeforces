#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

int solution(string& s) {
    vector<int> freq(26, 0);
    for (auto& ch : s) {
        freq[ch-'A']++;
    }
    int res = 0;
    for (int i=0; i<26; ++i) {
        if (freq[i] > i) {
            ++res;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> s;
        res[i] = solution(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}