#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

int N;

// to validate a subarray [l, r], only need to validate l and r
// check if another value of l exists before it
// check if another value of r exists after it
// mark if each index a first occurence and get suffix sum of last occurences to count
ll solution(vector<int>& v) {
    ll res = 0;
    set<int> foundR;
    foundR.insert(v[N-1]);
    // suff[i] = # of last occurences from [i, n-1]
    vector<int> suff(N, 0);
    suff[N-1] = 1;
    for (int i=N-2; i>=0; --i) {
        suff[i] = suff[i+1];
        if (foundR.find(v[i]) == foundR.end()) {
            foundR.insert(v[i]);
            ++suff[i];
        }
    }
    set<int> foundL;
    for (int i=0; i<N; ++i) {
        if (foundL.find(v[i]) == foundL.end()) {
            res += suff[i];
            foundL.insert(v[i]);
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
        vector<int> v(N);
        for (auto& x : v) {
            cin >> x;
        }
        res[i] = solution(v);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}