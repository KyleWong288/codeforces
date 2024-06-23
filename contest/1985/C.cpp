#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

int N;

int solve(vector<ll>& a) {
    int res = 0;
    ll sum = 0;
    set<ll> have;
    have.insert(0);
    for (auto& x : a) {
        sum += x;
        have.insert(x);
        if (sum % 2 == 0 && have.find(sum / 2) != have.end()) {
            ++res;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}