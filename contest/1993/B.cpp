#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// one odd converts everything odd, else everything originally even
// take the max odd and simulate
// worst case: # evens + 1, just add odd to largest even, and spam
int solve(vector<ll>& a) {
    int res = 0;
    ll maxOdd = -1;
    vector<ll> evens;
    for (auto& x : a) {
        if (x % 2) maxOdd = max(maxOdd, x);
        else evens.push_back(x);
    }
    sort(evens.begin(), evens.end());
    if (evens.size() == 0 || evens.size() == N) return 0;
    for (auto& x : evens) {
        if (maxOdd < x) {
            res += 2;
            maxOdd = maxOdd + x + x;
        }
        else {
            res += 1;
            maxOdd = max(maxOdd, maxOdd + x);
        }
    }
    return min(res, (int)evens.size()+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<ll> a(N);
        for (auto& x : a) cin >> x;
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}