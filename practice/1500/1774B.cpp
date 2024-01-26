#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N, M, K;

// bottlenecked by larger a[i]
// if n % k == 0, we have exactly n/k partitions, so no a[i] should be higher than this
// if n % k != 0, we have n/k normal partitions and one extra, only n % k values of a[i] can exist here
int solution(vector<int>& v) {
    int cap = N / K;
    int over = 0;
    for (auto& x : v) {
        if (x == cap + 1) {
            ++over;
        }
        if (x > cap + 1) {
            return 0;
        }
    }
    if (over > N % K) {
        return 0;
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M >> K;
        vector<int> v(M);
        for (auto& x : v) {
            cin >> x;
        }
        res[i] = solution(v);
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