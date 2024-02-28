#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int n;

int solve(vector<int>& a) {
    bool has1 = 0;
    bool has2 = 0;
    int sum = 0;
    for (auto& x : a) {
        sum = (sum + x) % 3;
        if (x % 3 == 1) has1 = 1;
        if (x % 3 == 2) has2 = 1;
    }
    if (sum == 0) {
        return 0;
    }
    else if (sum == 1) {
        if (has1) return 1;
        return 2;
    }
    else {
        return 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n;
        vector<int> a(n);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}