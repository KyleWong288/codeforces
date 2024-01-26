#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;

// simplify problem: what if we can only take l diagonals and r diagonals?
// each l diagonal intersects all r diagonals and creates 2 triangles: 2 * l * r
// now add horizontals: place h to intersect all 2 intersections: 4 * h * min(l,r)
// fixed sum maximal product should be equal, so l == r == h == x, so 2*x*x + 4*x*x = 6x^2, so 6x^2 >= input, so x = sqrt(input / 6) 
int solution(int n) {
    double val = sqrt(n / 6.0) * 3;
    int res = ceil(val);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int n;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n;
        res[i] = solution(n);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}