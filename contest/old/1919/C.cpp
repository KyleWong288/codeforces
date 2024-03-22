#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// how to reduce penalty? maximize the # of starts of increasing subarrays in s & t since starting indices arent penalized
// greedy?
int solution(vector<int>& a) {
    if (N <= 2) { return 0; }
    int res = 0;
    vector<int> v1 = {0};
    vector<int> v2 = {0};
    for (int i=0; i<N; ++i) {
        if (a[i] > v1.back() && a[i] > v2.back()) {
            // append to min
            v1.back() < v2.back() ? v1.push_back(a[i]) : v2.push_back(a[i]);
            ++res;
        }
        else if (a[i] > v1.back()) {
            v2.push_back(a[i]);
        }
        else if (a[i] > v2.back()) {
            v1.push_back(a[i]);
        }
        else {
            // append to min
            v1.back() < v2.back() ? v1.push_back(a[i]) : v2.push_back(a[i]);
        }
    }
    if (v1.size() > 1) {
        --res;
    }
    if (v2.size() > 1) {
        --res;
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