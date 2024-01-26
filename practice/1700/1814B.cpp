#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;

int score(int a, int b, int sz) {
    sz = max(1, sz);
    int res = sz - 1 + ((a + sz - 1) / sz) + ((b + sz - 1) / sz);
    return res;
}

// if the ending step size is s, we take ceil(len/s) steps in 1 dimension
// thus, find the optimal ending step size -> should have concavity so bs should work
// 1d concavity: s + len/s, answer is around sqrt(len)
// 2d concavity: s + a/s + b/s == s + (a+b)/s, answer is around sqrt(a+b)
int solution(int a, int b) {
    int res = 2e9;
    int sqsz = sqrt(a+b);
    for (int i=-1000; i<=1000; ++i) {
        int sz = max(1, sqsz + i);
        int score = sz - 1 + ((a + sz - 1) / sz) + ((b + sz - 1) / sz);
        res = min(res, score);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int a, b;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> a >> b;
        res[i] = solution(a, b);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}