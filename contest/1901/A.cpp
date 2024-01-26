#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, X;

// biggest diff, note bounce at N
int solution(vector<int>& a) {
    int res = a[0];
    for (int i=1; i<N; ++i) {
        res = max(res, a[i] - a[i-1]);
    }
    res = max(res, 2 * (X - a[N-1]));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> X;
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