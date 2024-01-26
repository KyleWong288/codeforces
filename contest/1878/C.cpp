#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

ll N, K, X;

// choose k biggest numbers, fail if you go under
// choose k smallest numbers, fail if you go over
int solution() {
    ll big = N * (N+1) / 2;
    ll small = (N-K) * (N-K+1) / 2;
    if (big - small < X) {
        return 0;
    }
    small = (K) * (K+1) / 2;
    if (small > X) {
        return 0;
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K >> X;
        res[i] = solution();
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