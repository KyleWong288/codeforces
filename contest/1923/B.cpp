#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

ll N, K;

// sort by distance, see if you can cumulatively kill all
int solve(vector<int>& hp, vector<int>& pos) {
    // stores <distance, hp left>
    vector<vector<int>> events;
    for (int i=0; i<N; ++i) {
        int dist = abs(pos[i]);
        events.push_back({dist - 1, hp[i]});
    }
    sort(events.begin(), events.end());
    ll use = 0;
    ll need = 0;
    int p = 0;
    for (int t=0; t<=N; ++t) {
        use += K;
        while (p < N && events[p][0] == t) {
            need += events[p][1];
            ++p;
        }
        if (need > use) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
        vector<int> hp(N);
        vector<int> pos(N);
        for (auto& x : hp) {
            cin >> x;
        }
        for (auto& x : pos) {
            cin >> x;
        }
        res[i] = solve(hp, pos);
    }
    for (auto& r : res) {
        cout << (r ? "YES\n" : "NO\n");
    }
    return 0;
}