#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, X;

int solution(vector<ll>& h) {
    ll l = 1;
    ll r = 2e9;
    while (l <= r) {
        ll m = (l + r) / 2;
        ll sum = 0;
        for (auto& x : h) {
            sum += max((ll)0, m - x);
        }
        if (sum <= X) {
            l = m+1;
        }
        else {
            r = m-1;
        }
    }
    return r;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> X;
        vector<ll> h(N);
        for (auto& x : h) {
            cin >> x;
        }
        res[i] = solution(h);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}