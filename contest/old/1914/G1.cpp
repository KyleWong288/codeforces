#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_set>
#include <queue>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
int N;

// checks if starting at idx can light all bulbs in [l, r]
// this is like a 2 directional jump game
bool lightAll(vector<ll>& c, vector<pair<int,int>>& intervals, pair<int,int> bounds, int start) {
    int startVal = c[start];
    int l = intervals[startVal].first;
    int r = intervals[startVal].second;
    // vis stores values
    unordered_set<int> vis;
    // queue stores values
    queue<int> q;
    for (int i=l; i<=r; ++i) {
        if (vis.find(c[i]) == vis.end()) {
            q.push(c[i]);
            vis.insert(c[i]);
        }
    }
    while (!q.empty()) {
        int val = q.front();
        q.pop();
        int newL = intervals[val].first;
        int newR = intervals[val].second;
        while (newL < l) {
            --l;
            if (vis.find(c[l]) == vis.end()) {
                vis.insert(c[l]);
                q.push(c[l]);
            }
        }
        while (newR > r) {
            ++r;
            if (vis.find(c[r]) == vis.end()) {
                vis.insert(c[r]);
                q.push(c[r]);
            }
        }
    }
    return (l == bounds.first && r == bounds.second);
}

// break into partitions: subarrays that for each value v, contains both occurrences of v
// find partitions "greedily", start with index 0 and build until condition reached, then start next partition
// the min size set demands exactly one lightbulb from each partition
// which light bulbs can be chosen in a given partition? brute force on each bulb
// final ans = product of choices over all partitions
void solution(vector<ll>& c) {
    // get partitions and intervals:
    vector<pair<int,int>> parts;
    vector<pair<int,int>> intervals(N+1);
    vector<int> freq(N+1, 0);
    for (int i=0; i<2*N; ++i) {
        int j = i+1;
        int unpaired = 1;
        freq[c[i]]++;
        intervals[c[i]].first = i;
        while (unpaired > 0) {
            freq[c[j]]++;
            if (freq[c[j]] == 1) {
                intervals[c[j]].first = j;
                ++unpaired;
            }
            if (freq[c[j]] == 2) {
                intervals[c[j]].second = j;
                --unpaired;
            }
            ++j;
        }
        parts.push_back({i, j-1});
        i = j-1;
    }
    // get choices per partions:
    ll size = parts.size();
    ll res = 1;
    for (auto& pr : parts) {
        unordered_set<int> good;
        for (int i=pr.first; i<=pr.second; ++i) {
            if (lightAll(c, intervals, pr, i)) {
                good.insert(i);
            }
        }
        res = res * (ll)good.size() % MOD;
    }
    cout << size << " " << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<ll> c(2*N);
        for (auto& x : c) {
            cin >> x;
        }
        solution(c);
    }
    return 0;
}