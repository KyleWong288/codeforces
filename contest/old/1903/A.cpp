#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// k > 1 or k == 1 and sorted
int solution(int n, int k, vector<int>& a) {
    if (k > 1) {
        return 1;
    }
    for (int i=1; i<n; ++i) {
        if (a[i] < a[i-1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int n, k;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solution(n, k, a);
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