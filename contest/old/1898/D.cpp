#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// no sign change has no effect: (a[i] - b[i]) + (a[j] - b[j]) == (a[i] - b[j]) + (a[j] - b[i])
// when our swap has a sign change, we get: (b[j] - a[i]) + (b[i] - a[j])
// pair the largest 2 b[i] with the smallest 2 a[i]
ll solution(vector<ll>& a, vector<ll>& b) {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<ll> a(N);
        vector<ll> b(N);
        for (auto& x : a) {
            cin >> x;
        }
        for (auto& x : b) {
            cin >> x;
        }
        res[i] = solution(a, b);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}