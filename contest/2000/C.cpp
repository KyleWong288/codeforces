#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;
typedef long long ll;

int N, M;

bool works(vector<int>& t, string& s) {
    if (s.size() != N) {
        return 0;
    }
    unordered_map<char,int> map;
    for (int i=0; i<N; ++i) {
        char c = s[i];
        if (map.find(c) != map.end() && map[c] != t[i]) {
            return 0;
        }
        map[c] = t[i];
    }
    unordered_map<int,int> freq;
    for (auto& pr : map) {
        freq[pr.second]++;
        if (freq[pr.second] > 1) return 0;
    }
    return 1;
}

void solve(vector<int>& t, vector<string>& ss) {
    for (auto& s : ss) {
        if (works(t, s)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> a(N);
        for (auto& x : a) cin >> x;
        cin >> M;
        vector<string> ss(M);
        for (auto& s : ss) cin >> s;
        solve(a, ss);
    }
    return 0;
}