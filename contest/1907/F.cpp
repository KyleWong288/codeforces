#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// finding pivot (start of array): sorted, drop, sorted. pivot is the drop
// returns -1 if the array is not in the format sorted, drop, sorted
int getPivot(vector<int>& a, int n) {
    int res = 0;
    bool drop = 0;
    for (int i=1; i<n; ++i) {
        if (a[i] < a[i-1]) {
            if (!drop) {
                res = i;
                drop = 1;
            }
            else {
                return -1;
            }
        }
    }
    if (drop && a[n-1] > a[0]) {
        return -1;
    }
    return res;
}

// doesnt make sense to shift, rev, shift -> you can achieve this with 1 rev
// doesnt make sense to do consecutive rev
// so rev can only be used at the start or end
int solution(vector<int>& a, int n) {
    int res = 1e9;
    int piv = getPivot(a, n);
    // in sorted order: sorted, drop, sorted
    // either (shift right side) or (rev, shift left side, rev)
    if (piv != -1) {
        if (piv == 0) {
            res = 0;
        }
        res = min(res, min(n - piv, piv + 2));
    }
    reverse(a.begin(), a.end());
    piv = getPivot(a, n);
    // in reverse sorted order: reverse sorted, drop, reverse sorted
    // either (shift right side, rev) or (rev, shift left side)
    if (piv != -1) {
        piv = n - piv - 1;
        res = min(res, min(n - piv - 1, piv + 1) + 1);
    }
    if (res == 1e9) {
        return -1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, N;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solution(a, N);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}