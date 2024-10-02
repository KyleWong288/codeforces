#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <numeric>
using namespace std;
typedef long long ll;

int N;

// for every char under n, best case correct
int solve(string& s) {
    vector<int> freq(4, 0);
    for (auto& ch : s) {
        if (ch == '?') continue;
        freq[ch-'A'] = min(freq[ch-'A'] + 1, N);
    }
    return accumulate(freq.begin(), freq.end(), 0);
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