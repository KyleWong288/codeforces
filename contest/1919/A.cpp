#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// odd a win, even b win
int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int a, b;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> a >> b;
        res[i] = (a + b) % 2;
    }
    for (auto& r : res) {
        if (r) {
            cout << "Alice" << endl;
        }
        else {
            cout << "Bob" << endl;
        }
    }
    return 0;
}