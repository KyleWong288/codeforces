#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, K;

// palindrome = all char freqs are even except for one
int solution(string& s) {
    vector<int> freq(26, 0);
    for (auto& ch : s) {
        freq[ch - 'a']++;
    }
    int cnt = 0;
    for (auto& f : freq) {
        if (f % 2) {
            ++cnt;
        }
    }
    if (cnt > K + 1) {
        return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K >> s;
        res[i] = solution(s);
    }
    for (auto& r : res) {
        if (r) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}