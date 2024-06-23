#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int solve(int n) {
    int res = 0;
    int high = 0;
    for (int i=2; i<=n; ++i) {
        int cur = i;
        int sum = 0;
        while (cur <= n) {
            sum += cur;
            cur += i;
        }
        if (high < sum) {
            high = sum;
            res = i;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    int n;
    for (int i=0; i<T; ++i) {
        cin >> n;
        res[i] = solve(n);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}