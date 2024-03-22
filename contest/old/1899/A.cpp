#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    int T, n;
    cin >> T;
    for (int i=0; i<T; ++i) {
        cin >> n;
        if (n % 3) {
            cout << "First" << endl;
        }
        else {
            cout << "Second" << endl;
        }
    }
    return 0;
}