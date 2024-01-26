#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// directed graph-ish
// simplify: say everything was len 1, only chars that appear odd # of times is start
// case 1. relative to final string, char is replaced (a -> xyz, x -> bcd)
// case 2. relative to final string, char isn't replaced (a -> xyz, x counted again in final ans)
// since the starting string doesn't have an in-edge, it's only counted once
char solution(vector<string>& t) {
    vector<int> freq(26, 0);
    for (auto& s : t) {
        for (auto& ch : s) {
            freq[ch-'a']++;
        }
    }
    for (int i=0; i<26; ++i) {
        if (freq[i] % 2) {
            return 'a' + i;
        }
    }
    return '#';
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<char> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<string> t(2*N+1);
        for (auto& x : t) {
            cin >> x;
        }
        res[i] = solution(t);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}