#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

int N;

// difference between consecutive squares are sum of odd numbers, the max difference between any two numbers in a is 1e9
// for each a[i], round it to the nearest square, then lookup based on the odd sum differences
// ex: a[i] = 14, needs to start at least 16, look for +9, +9+11, +9+11+13 ...
int solution(vector<ll>& a) {
    set<int> have;
    for (auto& x : a) {
        have.insert(x);
    }
    int perfs = 0;
    int res = 0;
    for (auto& val : a) {
        // find starting point:
        ll odd = 1;
        ll k = 3;
        while (k*k < val) {
            k++;
            odd += 2;
        }
        if (k*k == val) { ++perfs; }
        // count values with valid differences:
        int cnt = 0;
        ll diff = odd;
        while (val + diff <= 1e9) {
            if (have.find(val + diff) != have.end()) {
                ++cnt;
            }
            odd += 2;
            diff += odd;
        }
        res = max(res, cnt);
    }
    res = max(res, perfs);
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
        res[i] = solution(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}