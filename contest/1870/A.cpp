#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, X;

// satisfy mex, then spam x
int solution() {
    if (N < K || X < K-1) {
        return -1;
    }
    int high = X;
    if (X == K) {
        high--;
    }
    vector<int> v(N);
    for (int i=0; i<K; ++i) {
        v[i] = i;
    }
    for (int i=K; i<N; ++i) {
        v[i] = high;
    }
    int res = 0;
    for (auto& x : v) {
        res += x;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    vector<int> res(t);
    for (int i=0; i<t; ++i) {
        cin >> N >> K >> X;
        res[i] = solution();
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}