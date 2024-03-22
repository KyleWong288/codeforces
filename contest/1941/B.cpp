#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// just go l->r since edges force
int solve(vector<ll>& a) {
    for (int i=1; i<N-1; ++i) {
        a[i] -= a[i-1] * 2;
        a[i+1] -= a[i-1];
        a[i-1] -= a[i-1];
        if (a[i] < 0 || a[i+1] < 0) return 0;
    }
    for (int i=0; i<N; ++i) {
        if (a[i]) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << (r ? "YES\n" : "NO\n");
    }
    return 0;
}