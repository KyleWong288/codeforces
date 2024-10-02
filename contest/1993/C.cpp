#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, K;

// modulo each starting time by 2k, then make sure there exists some k-interval that contains everything
// for each r, get l = r - k + 1 -> the range[l,r] must have all start points
// the first usable r is the timestamp of the last chip installation
int solve(vector<int>& a) {
    // build array of start points
    vector<int> points(2*K);
    for (auto& x : a) {
        points[x % (2*K)]++;
    }
    // get window starting point
    int lastIdx = max_element(a.begin(), a.end()) - a.begin();
    int lastTime = a[lastIdx] % (2*K);
    // build initial window (1 before the last chip installation)
    int overlap = 0;
    int l = (lastTime - K + 2*K) % (2*K);
    int r = l;
    for (int i=0; i<K; ++i) {
        overlap += points[r];
        r = (r + 1) % (2*K);
    }
    // slide window
    for (int i=0; i<2*K; ++i) {
        overlap += points[r] - points[l];
        if (overlap == N) return a[lastIdx] + i;
        l = (l + 1) % (2*K);
        r = (r + 1) % (2*K);
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
        vector<int> a(N);
        for (auto& x : a) cin >> x;
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}