#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// cut dim1 in half and add that to dim2
int solve(int a, int b) {
    if (a % 2 == 0) {
        int x = a / 2;
        int y = b + x;
        if ((x != a && y != b) && (x != b && y != a)) {
            return 1;
        }
    }
    if (b % 2 == 0) {
        int x = b / 2;
        int y = a + x;
        if ((x != a && y != b) && (x != b && y != a)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int a, b;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> a >> b;
        res[i] = solve(a, b);
    }
    for (auto& r : res) {
        cout << (r ? "YES\n": "NO\n");
    }
    return 0;
}