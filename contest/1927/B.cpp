#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;
typedef long long ll;

int N;

void solve(vector<int>& trace) {
    string res = "";
    // stores <freq, char>
    unordered_map<char, int> freq;
    for (auto& f : trace) {
        for (char ch='a'; ch<='z'; ++ch) {
            if (freq[ch] == f) {
                freq[ch]++;
                res.push_back(ch);
                break;
            }
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> trace(N);
        for (auto& x : trace) {
            cin >> x;
        }
        solve(trace);
    }
    return 0;
}