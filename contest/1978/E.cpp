#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

int N, Q;


// 2 phase: do all op 1s, then all op 2s. Keep 0s in S, spam 1s in T, spam 1s in S
// there exists optimal T and S for the full string, substrings [l,r] only modify the edges of optT and optS in O(1)
// changes in optT: t[l] and t[r] can't flip
// changes in optS: s[l] and s[r] can't flip. Also, s[l+1] and s[r-1] may change since t[l] and t[r] changed
void solve(vector<int>& s, vector<int>& t, vector<vector<int>>& queries) {
    // build optimal
    vector<int> optS = s;
    vector<int> optT = t;
    for (int i=0; i<N-2; ++i) {
        if (s[i] + s[i+2] == 0) optT[i+1] = 1;
    }
    for (int i=0; i<N-2; ++i) {
        if (optT[i] + optT[i+2] == 2) optS[i+1] = 1;
    }
    // build ps on additional ones between optS and s
    vector<int> ps(N+1);
    for (int i=0; i<N; ++i) {
        ps[i+1] = ps[i] + optS[i];
    }
    // answer queries
    vector<int> res(Q);
    for (int q=0; q<Q; ++q) {
        int l = queries[q][0], r = queries[q][1];
        set<int> lose;
        if (!s[l] && optS[l]) {
            lose.insert(l);
        }
        if (!s[r] && optS[r]) {
            lose.insert(r);
        }
        if (l+1 < r && !t[l] && !s[l+1] && optS[l+1]) {
            lose.insert(l+1);
        }
        if (l < r-1 && !t[r] && !s[r-1] && optS[r-1]) {
            lose.insert(r-1);
        }
        res[q] = ps[r+1] - ps[l] - lose.size();
    }
    for (auto& x : res) {
        cout << x << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        string strS, strT;
        cin >> N >> strS >> strT >> Q;
        vector<int> s(N);
        vector<int> t(N);
        for (int i=0; i<N; ++i) {
            s[i] = strS[i] - '0';
        }
        for (int i=0; i<N; ++i) {
            t[i] = strT[i] - '0';
        }
        vector<vector<int>> queries(Q, vector<int>(2));
        for (auto& pr : queries) {
            cin >> pr[0] >> pr[1];
            pr[0]--;
            pr[1]--;
        }
        solve(s, t, queries);
    }
    return 0;
}