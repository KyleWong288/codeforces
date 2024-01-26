#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N;

// find all positive subarrays -> 0, [pos numbers], 0
// if subarray contains a 2, both 0s can be painted
// else, one 0 can be painted and prioritize left 0
int solution(vector<int>& v) {
    vector<bool> buy(v.size(), 1);
    // stores [l, r] for all positive subarrays
    vector<pair<int,int>> intervals;
    vector<bool> has2;
    int l = 0;
    int r = 0;
    while (l < N) {
        while (l < N && v[l] == 0) {
            ++l;
        }
        if (l >= N) {
            break;
        }
        r = l;
        bool find2 = false;
        while (r < N && v[r] != 0) {
            if (v[r] == 2) {
                find2 = true;
            }
            buy[r] = 0;
            ++r;
        }
        intervals.push_back({l, r-1});
        has2.push_back(find2);
        l = r;
    }
    for (int i=0; i<intervals.size(); ++i) {
        l = intervals[i].first;
        r = intervals[i].second;
        if (has2[i]) { // can paint left and right 0
            if (l > 0) {
                buy[l-1] = 0;
            }
            if (r < N-1) {
                buy[r+1] = 0;
            }
            buy[l] = 1;
        }
        else { // can only paint one 0, prioritize left
            if (l > 0 && buy[l-1]) {
                buy[l-1] = 0;
            }
            else if (r < N-1) {
                buy[r+1] = 0;
            }
            buy[l] = 1;
        }
    }
    int res = 0;
    for (auto b : buy) {
        res += b;
    }
    return res;
}

int main() {
    cin >> N;
    vector<int> v(N);
    for (auto& i : v) {
        cin >> i;
    }
    cout << solution(v) << endl;
    return 0;
}