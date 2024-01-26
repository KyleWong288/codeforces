#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// case 1: a[i] > a[i+1], so we don't need any additional chips (anything in i can be passed to i+1)
// case 2: a[i] < a[i+1], so we need a[i+1] - a[i] additional chips
ll solution(vector<ll>& c) {
    ll res = c[0] - 1;
    for (int i=1; i<N; ++i) {
        if (c[i] > c[i-1]) {
            res += c[i] - c[i-1];
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<ll> c(N);
        for (auto& x : c) {
            cin >> x;
        }
        res[i] = solution(c);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}