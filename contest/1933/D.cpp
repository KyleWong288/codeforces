#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// small to large is normally good
// if everyone is divisble by some number, and that number exists > once, we fail
int solve(vector<int>& a) {
    sort(a.begin(), a.end());
    int bad = a[0];
    if (a[1] != bad) return 1;
    for (int i=2; i<N; ++i) {
        if (a[i] % bad) return 1;
    }
    return 0;
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
        cout << (r ? "YES\n" : "NO\n");
    }
    return 0;
}