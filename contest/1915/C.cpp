#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <numeric>
#include <unordered_set>
using namespace std;
typedef long long ll;

int N;
vector<ll> squares(2e7+1, 0);

int solution(vector<ll>& a) {
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    auto it = lower_bound(squares.begin(), squares.end(), sum);
    if (*it == sum) {
        return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (ll i=1; i<=2e7; ++i) {
        squares[i] = i*i;
    }
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solution(a);
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