#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

int N, M;

// interval decomp and sort
// track the leftmost and rightmost interval pt for each time step with a map
// if theres a spot with 0 events, just place all events and get the max
// what if theres no spot with 0 events for the current time step?
// "emptiest" spots are always 1 or m, just track the # of intervals that intersect these points for the current time step
int solution(vector<vector<int>>& pairs) {
    int res = 0;
    // stores <time, +1/-1, left, right>
    vector<vector<int>> events(2*N);
    for (int i=0; i<N; ++i) {
        events[2*i] = {pairs[i][0], 1, pairs[i][0], pairs[i][1]+1};
        events[2*i+1] = {pairs[i][1]+1, -1, pairs[i][0], pairs[i][1]+1};
    }
    sort(events.begin(), events.end());
    // stores <time step, freq> for all events that intersect the current time step
    map<int,int> curEvents;
    int overlaps = 0;
    for (auto& e : events) {
        // add interval to curEvents
        if (e[1] == 1) {
            curEvents[e[2]]++;
            curEvents[e[3]]++;
        }
        // remove interval from curEvents
        else {
            curEvents[e[2]]--;
            curEvents[e[3]]--;
        }
        overlaps += e[1];
        int lose = min(curEvents[1], curEvents[M+1]);
        res = max(res, overlaps - lose);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<vector<int>> prs(N, vector<int>(2));
        for (int j=0; j<N; ++j) {
            cin >> prs[j][0] >> prs[j][1];
        }
        res[i] = solution(prs);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}