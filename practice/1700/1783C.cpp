#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N, M;

// we want as many wins as possible, get w by greedily choosing smallest prep times
// if we don't beat the opponent at index w, they win w+1 times, so see if we can shift our greedy choices to beat them
// no point in shifting greedy choices to beat any opponent past w, since they'll always have >= w+1 wins even if we beat them
int solution(vector<int>& v) {
    vector<pair<int,int>> opps(N);
    for (int i=0; i<N; ++i) {
        opps[i] = {v[i], i};
    }
    sort(opps.begin(), opps.end());
    vector<bool> taken(N, 0);
    int take = 0;
    int sum = 0;
    while (take < N && sum + opps[take].first <= M) {
        sum += opps[take].first;
        taken[opps[take].second] = 1;
        ++take;
    }
    vector<int> wins(N, 0);
    // res is the count of people with more wins
    int res = 1;
    for (int i=0; i<N; ++i) {
        wins[i] = i;
        if (!taken[i]) {
            wins[i]++;
        }
        if (wins[i] > take) {
            ++res;
        }
    }
    // if we don't beat player at index w, see if we can
    if (take > 0 && take < N && !taken[take]) {
        if (sum - opps[take-1].first + v[take] <= M) {
            --res;
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<int> v(N);
        for (auto& x : v) {
            cin >> x;
        }
        res[i] = solution(v);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}