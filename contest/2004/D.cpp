#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_map>
#include <set>
using namespace std;
typedef long long ll;

int N, Q;

// maps <color type, set of city locations with that color type>
unordered_map<string, set<int>> colMap;

// gets the best dist between l and r, using a intermediate hop of type
int getDist(string type, int l, int r) {
    int res = 1e9;
    // try in between [l,r]
    auto it = colMap[type].lower_bound(l);
    if (it != colMap[type].end() && l <= *it && *it <= r) {
        return r - l;
    }
    // try closest to l
    if (it != colMap[type].begin()) {
        --it;
        res = min(res, (l - *it) + (r - *it));
    }
    // try closest to r
    it = colMap[type].lower_bound(r);
    if (it != colMap[type].end()) {
        res = min(res, (*it - r) + (*it - l));
    }
    return res;
}

// only interesting queries are when the 2 cities have no overlapping colors: we need to take exactly one hop
// hop is in between the cities: cost is just distance, best case
// hop is outside the cities: take modified distance
void solve(vector<string>& cities, vector<vector<int>>& queries) {
    colMap.clear();
    for (int i=0; i<N; ++i) {
        colMap[cities[i]].insert(i);
    }
    unordered_map<string, int> type;
    type.insert({"BG", 0});
    type.insert({"BR", 1});
    type.insert({"BY", 2});
    type.insert({"GR", 3});
    type.insert({"GY", 4});
    type.insert({"RY", 5});
    // solve:
    for (auto& q : queries) {
        int res = 1e9;
        int l = q[0], r = q[1];
        string typeL = cities[l], typeR = cities[r];
        if (type[typeL] + type[typeR] == 5) {
            for (auto& pr : type) {
                if (pr.first != typeL && pr.first != typeR) {
                    res = min(res, getDist(pr.first, l, r));
                }
            }
        }
        else {
            res = r - l;
        }
        if (res == 1e9) res = -1;
        cout << res << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    while (T--) {
        cin >> N >> Q;
        vector<string> cities(N);
        for (auto& s : cities) cin >> s;
        vector<vector<int>> queries(Q, vector<int>(2));
        for (auto& q : queries) {
            cin >> q[0] >> q[1];
            --q[0], --q[1];
            sort(q.begin(), q.end());
        }
        solve(cities, queries);
    }
    return 0;
}