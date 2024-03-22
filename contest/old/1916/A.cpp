#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int n, k;

void solution(vector<int>& b) {
    int cur = 2023;
    int remain = -1;
    for (auto& x : b) {
        if (cur % x) {
            cout << "NO" << endl;
            return;
        }
        cur /= x;
    }
    cout << "YES" << endl;
    cout << cur << " ";
    for (int i=0; i<k-1; ++i) {
        cout << 1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    while (T--) {
        cin >> n >> k;
        vector<int> b(n);
        for (auto& x : b) {
            cin >> x;
        }
        solution(b);
    }
    return 0;
}