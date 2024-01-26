#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

// n mod 3 = 0: mod1 + mod1 + mod1 or mod2 + mod2 + mod2
// n mod 3 = 1: mod1 + mod1 + mod2
// n mod 3 = 2: mod1 + mod2 + mod2
void solution(int N) {
    if (N % 3 == 0) {
        if (N < 12) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            cout << 1 << " " << 4 << " " << N - 5 << endl;
        }
    }
    else if (N % 3 == 1) {
        if (N < 7) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            cout << 1 << " " << 2 << " " << N - 3 << endl;
        }
    }
    else {
        if (N < 8) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            cout << 1 << " " << 2 << " " << N - 3 << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        solution(N);
    }
    return 0;
}