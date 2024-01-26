#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <set>
using namespace std;

vector<string> s;
int t, q;

// strings are equal if every index of a character mismatch is blocked
// to track unblocking via time, use a queue
// to track mismatched indices, use a set
// swaps means you update your desired set of mismatched indices
void solution(vector<vector<int>>& queries) {
    int cntMM = 0;
    for (int i=0; i<s[1].size(); ++i) {
        if (s[1][i] != s[2][i]) {
            ++cntMM;
        }
    }
    // stores <time, index that gets unblocked>
    queue<pair<int,int>> q;
    // stores only indices that are mismatched
    set<int> setMM;
    for (int i=0; i<queries.size(); ++i) {
        if (!q.empty() && q.front().first <= i - t) {
            setMM.erase(q.front().second);
            q.pop();
        }
        int type = queries[i][0];
        if (type == 1) {
            int p = queries[i][1] - 1;
            if (s[1][p] != s[2][p]) {
                q.push({i, p});
                setMM.insert(p);
            }
        }
        else if (type == 2) {
            int i1 = queries[i][1];
            int p1 = queries[i][2]-1;
            int i2 = queries[i][3];
            int p2 = queries[i][4]-1;
            // compare before and after to update cntMM
            bool p1MatchB = (s[1][p1] == s[2][p1]);
            bool p2MatchB = (s[1][p2] == s[2][p2]);
            char temp = s[i1][p1];
            s[i1][p1] = s[i2][p2];
            s[i2][p2] = temp;
            bool p1MatchA = (s[1][p1] == s[2][p1]);
            bool p2MatchA = (s[1][p2] == s[2][p2]);
            cntMM += (p1MatchB - p1MatchA) + (p2MatchB - p2MatchA);
        }
        else {
            if (setMM.size() == cntMM) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    int type, t1, t2, p1, p2;
    s.resize(3);
    while (T--) {
        cin >> s[1] >> s[2] >> t >> q;
        vector<vector<int>> v(q);
        for (int i=0; i<q; ++i) {
            cin >> type;
            if (type == 1) {
                cin >> p1;
                v[i] = {type, p1};
            }
            else if (type == 2) {
                cin >> t1 >> p1 >> t2 >> p2;
                v[i] = {type, t1, p1, t2, p2};
            }
            else {
                v[i] = {type};
            }
        }
        solution(v);
    }
    return 0;
}