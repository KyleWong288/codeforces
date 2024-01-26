#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, K;

// easy way to generate unique palid substrs is spamming a single char, len chars -> len new palids
// easy way to not generate new palid substrs is spamming 3 chars like "xyz"
// conveniently n >= 3 and x1 >= 3 and c1 >= 3 so no weird edge cases
void solution(vector<pair<int,int>>& queries) {
    string res = "";
    int curLen = 0;
    int curPalids = 0;
    vector<char> delimiters = {'x','y','z'};
    int ptrD = 0;
    for (int i=0; i<K; ++i) {
        int len = queries[i].first;
        int goal = queries[i].second;
        // spam single char
        int spam = goal - curPalids;
        if (i == 0) { spam -= 3; }
        if (spam > len - curLen || goal > len) {
            cout << "NO" << endl;
            return;
        }
        for (int j=0; j<spam; ++j) {
            res += ('a' + i);
        }
        // spam delimiter (xyz)
        while (res.size() < len) {
            res += delimiters[ptrD];
            ptrD = (ptrD + 1) % 3;
        }
        curLen = len;
        curPalids = goal;
    }
    cout << "YES" << endl;
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<pair<int,int>> queries(K);
        for (int i=0; i<K; ++i) {
            cin >> queries[i].first;
        }
        for (int i=0; i<K; ++i) {
            cin >> queries[i].second;
        }
        solution(queries);
    }
}