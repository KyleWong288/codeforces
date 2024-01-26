#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// for some x in [0, m], n ^ x = k, so x = n ^ k, so n ^ k <= m
// thus, construct the min k such that n ^ k > m, just break into cases based on bits in n and m
// generally, we want to construct k so n ^ k == m, then perturb k so n ^ k > m
// perturb case 1: (n has 1, m has 0) -> 0, rest is 0
// perturb case 2: (n has 0, m has 0) -> 0, but last occurrence of this is 1 and then make rest 0
// if (1) and (2) occur, just do (1)
int solution(int n, int m) {
    // get perturb case indicators:
    int spam0 = -1;
    int flip0 = -1;
    for (int b=30; b>=0; --b) {
        int bn = (n >> b) & 1;
        int bm = (m >> b) & 1;
        if (bn && !bm && spam0 == -1) {
            spam0 = b;
        }
        if (!bn && !bm) {
            flip0 = b;
        }
    }
    // construct res:
    int res = 0;
    for (int b=30; b>=0; --b) {
        int bn = (n >> b) & 1;
        int bm = (m >> b) & 1;
        if (bn && bm) { // (1, 1) -> 0
            res += 0;
        }
        else if (bn && !bm) { // (1, 0) -> 0, rest 0
            return res;
        }
        else if (!bn && bm) { // (0, 1) -> 1
            res += (1 << b);
        }
        else { // (0, 0) -> 0, but last occurrence of this is 1 and then make rest 0
            if (b == flip0 && spam0 == -1) {
                res += (1 << b);
                return res;
            }
            else {
                res += 0;
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int n, m;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> m;
        res[i] = solution(n, m);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}