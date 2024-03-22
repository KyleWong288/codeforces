#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

int N;

// cache and lookup difference in prefix sums
int solution(vector<ll>& a) {
    set<ll> diffs;
    diffs.insert(0);
    ll sumOdd = 0;
    ll sumEven = 0;
    for (int i=1; i<=N; ++i) {
        if (i % 2) {
            sumOdd += a[i];
        }
        else {
            sumEven += a[i];
        }
        ll diff = sumOdd - sumEven;
        if (diffs.find(diff) != diffs.end()) {
            return 1;
        }
        diffs.insert(diff);
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<ll> a(N+1);
        for (int j=1; j<=N; ++j) {
            cin >> a[j];
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