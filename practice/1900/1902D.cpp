#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

int N, Q;

// range query good -> given a starting point (sx,sy), we can lookup if a (sx+dx,sy+dy) exists
// what if (x,y) before or after the reversal? always works since we can ignore reversal
// what if (x,y) inside reversal [l,r] ? the path we take is 0 -> l, r -> some unknown middle pos p
// pref at l: (sx,sy)           suff at r: (ex,ey)          diff between (sx,sy) and (x,y): (dx, dy)
// lookup if (ex+dx, ey+dy) exists in between [l,r] for the suffix sums
// map each point to all of its occurences to handle lookup queries
void solve(string& s, vector<vector<int>>& queries) {
    vector<bool> res(Q, 0);
    // get pref/suff and occurrences:
    vector<pair<int,int>> pref(N+1);
    vector<pair<int,int>> suff(N+2);
    map<pair<int,int>, vector<int>> occP;
    map<pair<int,int>, vector<int>> occS;
    pair<int,int> cur = {0,0};
    occP[cur].push_back(0);
    for (int i=0; i<N; ++i) {
        if (s[i] == 'L') cur.first--;
        else if (s[i] == 'R') cur.first++;
        else if (s[i] == 'U') cur.second++;
        else cur.second--;
        pref[i+1] = cur;
        occP[cur].push_back(i+1);
    }
    cur = {0,0};
    occS[cur].push_back(N+1);
    for (int i=N-1; i>=0; --i) {
        if (s[i] == 'L') cur.first--;
        else if (s[i] == 'R') cur.first++;
        else if (s[i] == 'U') cur.second++;
        else cur.second--;
        suff[i+1] = cur;
        occS[cur].push_back(i+1);
    }
    for (auto& pr : occS) {
        reverse(pr.second.begin(), pr.second.end());
    }
    // answer queries:
    for (int q=0; q<Q; ++q) {
        int x = queries[q][0], y = queries[q][1], l = queries[q][2], r = queries[q][3];
        pair<int,int> goal = {x,y};
        // check before/after [l,r]:
        if (occP.find(goal) != occP.end()) {
            if (occP[goal][0] < l || occP[goal].back() > r) {
                res[q] = 1;
                continue;
            }
        }
        // check inside [l,r]:
        pair<int,int> startL = pref[l-1];
        pair<int,int> startR = suff[r+1];
        pair<int,int> diff = {x - startL.first, y - startL.second};
        pair<int,int> want = {startR.first + diff.first, startR.second + diff.second};
        if (occS.find(want) != occS.end()) {
            auto it = lower_bound(occS[want].begin(), occS[want].end(), l);
            if (it != occS[want].end() && *it <= r) {
                res[q] = 1;
            }
        }
    }
    for (auto r : res) {
        cout << (r ? "YES\n" : "NO\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> N >> Q >> s;
    vector<vector<int>> queries(Q, vector<int>(4));
    for (auto& q : queries) {
        cin >> q[0] >> q[1] >> q[2] >> q[3];
    }
    solve(s, queries);
    return 0;
}