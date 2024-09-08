#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

int solve(vector<int>& a) {
    sort(a.begin(), a.end());
    return (N == 2 && a[1] - a[0] > 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> a(N);
        for (auto& x : a) cin >> x;
        res[i] = solve(a);
    }
    for (auto& r : res) {
        if (r) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}