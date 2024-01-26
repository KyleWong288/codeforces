#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

int N;

// case 1: a[i] == a[j]
// case 2: a(i, j) = (1, 2), only case is 2^4 and 4^2
ll solution(vector<int>& a) {
    ll res = 0;
    map<int, int> freq;
    for (auto& x : a) {
        res += freq[x];
        if (x == 1) {
            res += freq[2];
        }
        if (x == 2) {
            res += freq[1];
        }
        freq[x]++;
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
        vector<int> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solution(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}