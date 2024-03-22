#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

void solution(int n, int k) {
    vector<int> res(n);
    res[0] = 1;
    for (int i=1; i<k; ++i) {
        res[i] = res[i-1]+1;
    }
    for (int i=k; i<n; ++i) {
        res[i] = n - i + k;
    }
    for (auto& r : res) {
        cout << r << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int n, k;
    while (T--) {
        cin >> n >> k;
        solution(n, k);
    }
    return 0;
}