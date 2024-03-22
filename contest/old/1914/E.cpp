#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

int N;

// take for a: (a[i] - 1) + b[i]
// take for b: (b[i] - 1) + a[i]
// if you have ties, take the one that fucks up the next player more: a take larger b[i], b take larger a[i]
ll solution(vector<ll>& a, vector<ll>& b) {
    // stores <sum-1, a[i] or b[i], index>
    vector<vector<ll>> movesA;
    vector<vector<ll>> movesB;
    for (int i=0; i<N; ++i) {
        ll sum = a[i] + b[i] - 1;
        movesA.push_back({sum, b[i], i});
        movesB.push_back({sum, a[i], i});
    }
    int p1 = 0, p2 = 0;
    sort(movesA.rbegin(), movesA.rend());
    sort(movesB.rbegin(), movesB.rend());
    // 0 is unused, 1 is a, 2 is b
    vector<int> used(N, 0);
    for (int i=0; i<N; ++i) {
        // a turn
        if (i % 2 == 0) {
            while (used[movesA[p1][2]]) {
                ++p1;
            }
            int idx = movesA[p1][2];
            used[idx] = 1;
            ++p1;
        }
        // b turn
        else {
            while (used[movesB[p2][2]]) {
                ++p2;
            }
            int idx = movesB[p2][2];
            used[idx] = 2;
            ++p2;
        }
    }
    ll sumA = 0;
    ll sumB = 0;
    for (int i=0; i<N; ++i) {
        if (used[i] == 1) {
            sumA += a[i] - 1;
        }
        else {
            sumB += b[i] - 1;
        }
    }
    return sumA - sumB;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<ll> a(N);
        vector<ll> b(N);
        for (auto& x : a) {
            cin >> x;
        }
        for (auto& x : b) {
            cin >> x;
        }
        res[i] = solution(a, b);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}