#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// diagonal down and then up
int solution(int n, int m) {
    return max(n, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        int n, m;
        cin >> n >> m;
        res[i] = solution(n, m);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}