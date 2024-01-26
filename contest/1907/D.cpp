#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// bs, track the current range you can be
int solution(vector<pair<int,int>>& ints, int n) {
    int l = 0;
    int r = 1e9;
    while (l <= r) {
        int m = (l + r) / 2;
        bool good = 1;
        pair<int,int> range = {0, 0};
        for (auto& pr : ints) {
            if (pr.second < range.first - m) { // target is too left
                good = 0;
                break;
            }
            else if (pr.first > range.second + m) { // target is too right
                good = 0;
                break;
            }
            else { // compute new range by merging
                range.first -= m;
                range.second += m;
                range.first = max(range.first, pr.first);
                range.second = min(range.second, pr.second);
            }
        }
        if (good) {
            r = m-1;
        }
        else {
            l = m+1;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, N;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<pair<int,int>> ints(N);
        for (auto& pr : ints) {
            cin >> pr.first >> pr.second;
        }
        res[i] = solution(ints, N);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}