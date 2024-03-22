#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// we have some dominant most freq char, it can always be erased at the endpoints of the subarray (other chars adjacent)
// odd always has 1 left
int solution(string& s, int n) {
    int maxF = 0;
    int maxI = 0;
    vector<int> freq(26, 0);
    for (auto& ch : s) {
        freq[ch-'a']++;
        if (freq[ch-'a'] > maxF) {
            maxF = freq[ch-'a'];
            maxI = ch-'a';
        }
    }
    int other = 0;
    for (int i=0; i<26; ++i) {
        if (i != maxI) {
            other += freq[i];
        }
    }
    if (other >= maxF) {
        return n % 2;
    }
    else {
        return maxF - other;
    }
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