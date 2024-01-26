#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// need alternating parity, 2 adjacent with same parity means its divisible by 2
// thus, odd number always fails since we need to put that extra odd somewhere
// 3 consecutive values is bad -> k, k+1, k+2 = 3k+3 so divisible by 3
// pattern: 2,1,4,3,6,5... ???
void solution(int n) {
    if (n % 2) {
        if (n == 1) {
            cout << 1 << endl;
        }
        else {
            cout << -1 << endl;
        }
        return;
    }
    for (int i=0; i<n; i+=2) {
        cout << i+2 << " " << i+1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int n;
    while (T--) {
        cin >> n;
        solution(n);
    }
    return 0;
}