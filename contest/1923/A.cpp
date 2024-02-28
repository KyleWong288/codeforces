#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int n;

bool good(vector<int>& a, int total, int start) {
    for (int i=0; i<total; ++i) {
        if (a[start + i] == 0) return 0;
    }
    return 1;
}

// always move the last chip lol
int solve(vector<int>& a) {
    int res = 0;
    int first = -1;
    int total = 0;
    for (int i=0; i<n; ++i) {
        if (a[i] == 1) {
            if (first == -1) first = i;
            ++total;
        }
    }
    while (!good(a, total, first)) {
        int last0 = -1;
        int last1 = -1;
        for (int i=0; i<n; ++i) {
            if (a[i] == 1) last1 = i;
        }
        for (int i=0; i<last1; ++i) {
            if (a[i] == 0) last0 = i;
        }
        swap(a[last0], a[last1]);
        ++res;
    }
    return res;
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