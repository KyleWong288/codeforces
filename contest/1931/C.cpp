#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// spam the left most or right most number
int solve(vector<int>& a) {
    // left:
    int l = 0;
    while (l < N && a[0] == a[l]) {
        ++l;
    }
    --l;
    // right:
    int r = N-1;
    while (r >= 0 && a[N-1] == a[r]) {
        --r;
    }
    ++r;
    int takeL = l + 1;
    int takeR = N - r;
    if (a[0] == a[N-1]) {
        int res = max(0, N - takeL - takeR);
        return res;
    }
    else {
        int res = min(N - takeL, N - takeR);
        return res;
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