#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int digsum(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

// just keep adding 1 until it works
int solution(int x, int k) {
    int cur = x;
    while (digsum(cur) % k) {
        cur++;
    }
    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, x, k;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> x >> k;
        res[i] = solution(x, k);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}