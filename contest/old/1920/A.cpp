#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// process 1 and 2 first, then subtract out 3
int solution(vector<vector<int>>& queries) {
    int l = 0;
    int r = 1e9;
    for (auto& pr : queries) {
        if (pr[0] == 1) {
            l = max(l, pr[1]);
        }
        if (pr[0] == 2) {
            r = min(r, pr[1]);
        }
    }
    if (r < l) {
        return 0;
    }
    int sub = 0;
    for (auto& pr : queries) {
        if (pr[0] == 3 && l <= pr[1] && pr[1] <= r) {
            ++sub;
        } 
    }
    int res = (r - l + 1) - sub;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<vector<int>> queries(N, vector<int>(2));
        for (auto& pr : queries) {
            cin >> pr[0] >> pr[1];
        }
        res[i] = solution(queries);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}