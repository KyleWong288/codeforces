#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// mss
int solution(vector<int>& a) {
    int res = a[0];
    int sum = max(a[0], 0);
    for (int i=1; i<N; ++i) {
        if ((a[i] + 2000) % 2 == (a[i-1] + 2000) % 2) {
            sum = a[i];
            res = max(res, sum);
            sum = max(sum, 0);
        }
        else {
            sum += a[i];
            res = max(res, sum);
            sum = max(sum, 0);
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