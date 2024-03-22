#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// theres one you eventually want to spam, only spam this one
// brute force over all i: you reach index i, then spam largest from [0:i]
int solution(int n, int k, vector<int>& a, vector<int>& b) {
    int pref = 0;
    int spam = 0;
    int res = 0;
    for (int i=0; i<min(n,k); ++i) {
        pref += a[i];
        spam = max(spam, b[i]);
        int newRes = pref + (k - i - 1) * spam;
        res = max(res, newRes);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    int n, k;
    for (int i=0; i<T; ++i) {
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for (auto& x : a) {
            cin >> x;
        }
        for (auto& x : b) {
            cin >> x;
        }
        res[i] = solution(n, k, a, b);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}