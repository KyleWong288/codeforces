#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// the operation always generates an even number
// minimize = pair diff parity, maximize = pair same parity
// p1 wants to combine odd & odd, p2 wants to combine odd & even
// res[i] = psum[0:i], subtract # of (odd & even) pairs taken
// # of (odd & even) pairs: 1 per every 3 odds -> odds / 3, and one extra if the remainder is 1
void solution(vector<ll>& a) {
    vector<ll> res(N);
    ll sum = a[0];
    ll odds = (a[0] % 2);
    res[0] = sum;
    for (int i=1; i<N; ++i) {
        sum += a[i];
        odds += (a[i] % 2);
        ll sub = (odds / 3) + (odds % 3 == 1);
        res[i] = sum - sub;
    }
    for (auto& r : res) {
        cout << r << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        solution(a);
    }
    return 0;
}