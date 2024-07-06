#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// max plus last
int solve(vector<int>& a) {
    vector<int> sa = a;
    sort(sa.begin(), sa.end());
    if (sa[N-1] == a[N-1]) {
        return sa[N-2] + a[N-1];
    }
    else {
        return sa[N-1] + a[N-1];
    }
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