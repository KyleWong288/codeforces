#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;

// naive string match, find all intervals in t that can be with matched with any string s
// sort intervals and jump game bfs, store the intervals that end on the furthest endpt at each layer
void solution(string& t, vector<string>& v) {
    int N = t.size();
    // find all intervals:
    // intervals stores <l, r, which index in v>
    vector<vector<int>> intervals;
    string comp;
    for (int i=0; i<v.size(); ++i) {
        int len = v[i].size();
        for (int j=0; j<=N-len; ++j) {
            comp = t.substr(j, len);
            if (v[i] == comp) {
                intervals.push_back({j, j + len - 1, i});
            }
        }
    }
    sort(intervals.begin(), intervals.end());
    // queue stores intervals
    queue<vector<int>> q;
    // res stores intervals
    vector<vector<int>> res;
    int end = -1;
    int i = 0;
    // init first layer of bfs (anything that starts at 0):
    while (i < intervals.size() && intervals[i][0] == 0) {
        q.push(intervals[i]);
        ++i;
    }
    // regular bfs:
    while (!q.empty()) {
        res.push_back({-1,-1,-1});
        // find new endpt
        int sz = q.size();
        while (sz--) {
            vector<int> cur = q.front();
            q.pop();
            if (cur[1] > end) {
                end = cur[1];
                res.back() = cur;
            }
        }
        if (end >= N-1) { break; }
        // push new elements up to endpt
        while (i < intervals.size() && intervals[i][0] <= end+1) {
            q.push(intervals[i++]);
        }
    }
    if (end < N-1) {
        cout << -1 << endl;
        return;
    }
    cout << res.size() << endl;
    for (auto& r : res) {
        cout << r[2]+1 << " " << r[0]+1 << endl;
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, N;
    cin >> T;
    string t;
    while (T--) {
        cin >> t;
        cin >> N;
        vector<string> v(N);
        for (auto& s : v) {
            cin >> s;
        }
        solution(t, v);
    }
    return 0;
}