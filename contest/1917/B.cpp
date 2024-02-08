#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

int N;

// on k ops: of the first k+1 elements, k of them are gone -> how many unique chars are in this range
// we can prepend a unique char to the suffix, so just add the # of unique chars
ll solve(string& s) {
    ll res = 0;
    set<char> unq;
    for (int k=0; k<N; ++k) {
        unq.insert(s[k]);
        res += unq.size();
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    string s;
    for (int i=0; i<T; ++i) {
        cin >> N >> s;
        res[i] = solve(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}