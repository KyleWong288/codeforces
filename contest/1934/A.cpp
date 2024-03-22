#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;

int N;

// big1, small1, big2, small2
int solve(vector<int>& a) {
    sort(a.begin(), a.end());
    int res = abs(a[N-1] - a[0]) + abs(a[0] - a[N-2]) + abs(a[N-2] - a[1]) + abs(a[1] - a[N-1]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> a(N);
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