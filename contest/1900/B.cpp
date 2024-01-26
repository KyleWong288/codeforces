#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// try to equate x and y, where x >= y
bool canEquate(int x, int y, int z) {
    if (x > y) {
        swap(x, y);
    }
    int diff = x - y;
    if (diff % 2) { return 0; }
    int ops = diff / 2;
    if (z >= ops) {
        return 1;
    }
    return 0;
}

// we want to make a pair of equal numbers
void solution(int a, int b, int c) {
    bool resA = canEquate(b, c, a);
    bool resB = canEquate(a, c, b);
    bool resC = canEquate(a, b, c);
    cout << resA << " " << resB << " " << resC << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, A, B, C;
    cin >> T;
    while (T--) {
        cin >> A >> B >> C;
        solution(A, B, C);
    }
    return 0;
}