#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int solution(int a, int b, int c) {
    if (a != b && a != c) {
        return a;
    }
    if (b != c && b != a) {
        return b;
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    int a,b,c;
    for (int i=0; i<T; ++i) {
        cin >> a >> b >> c;
        res[i] = solution(a,b,c);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}