#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;


// greedy works for all vals <= 30 except 12, 20, 23
// why 30? LCM, fastest way to get 30 is always 2x15
// 12, 20, 23, try special. otherwise, do greedy.
int solve(int n) {
    vector<int> vals = {15,10,6,3,1};
    int res = 0;
    int cur = n;
    for (auto& v : vals) {
        res += cur / v;
        cur %= v; 
    }
    if (n >= 12) {
        int res2 = 2;
        cur = n - 12;
        for (auto& v : vals) {
            res2 += cur / v;
            cur %= v;
        }
        res = min(res, res2);
    }
    if (n >= 20) {
        int res2 = 2;
        cur = n - 20;
        for (auto& v : vals) {
            res2 += cur / v;
            cur %= v;
        }
        res = min(res, res2);
    }
    if (n >= 23) {
        int res2 = 3;
        cur = n - 23;
        for (auto& v : vals) {
            res2 += cur / v;
            cur %= v;
        }
        res = min(res, res2);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int n;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n;
        res[i] = solve(n);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}