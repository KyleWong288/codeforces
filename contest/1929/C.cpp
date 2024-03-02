#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;


// guaranteed to make anything [0, a-1] since we pick any amount y to lose
int solve(ll k, ll x, ll a) {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    ll k, x, a;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> k >> x >> a;
        res[i] = solve(k, x, a);
    }
    for (auto& r : res) {
        cout << (r ? "YES\n" : "NO\n");
    }
    return 0;
}