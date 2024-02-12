#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;

// center around 0 by subtracting all by 1
// how can we simplify problem?: solve for fixed k or len, split into inc/dec
// inc: [0,1,2,3,2,1, 0,1,2,3,2,1] -> [0,1,2,3,4,5, 0,1,2,3,4,5]
// dec: [0,1,2,3,2,1, 0,1,2,3,2,1] -> [0,5,4,3,2,1, 0,5,4,3,2,1]
// inc: [(unknown...), 0, 1, 2, ... x]. We know where prev 0 is. unknown len (start to next known 0) = n - x
// dec: [(unknown...), x, x-1, ..., 0]. We know where next 0 is. unknown len (start to next known 0) = n + x
// how can we divide len evenly into cyclic chunks of size 2k-2? 2k-2 must be an even divisor of len, brute force divisors in sqrt(len)
int solve(int n, int x) {
    --n;
    --x;
    set<int> good;
    // inc:
    int len = n - x;
    int end = sqrt(len);
    vector<int> divs;
    for (int i=1; i<=end; ++i) {
        int j = len / i;
        if (i * j == len) {
            if (i % 2 == 0) divs.push_back(i);
            if (j % 2 == 0) divs.push_back(j);
        }
    }
    for (auto& d : divs) {
        int k = (d + 2) / 2;
        if (k > x) good.insert(k);
    }
    // dec:
    len = n + x;
    end = sqrt(len) * 2;
    divs.clear();
    for (int i=1; i<=end; ++i) {
        int j = len / i;
        if (i * j == len) {
            if (i % 2 == 0) divs.push_back(i);
            if (j % 2 == 0) divs.push_back(j);
        }
    }
    for (auto& d : divs) {
        int k = (d + 2) / 2;
        if (k > x) good.insert(k);
    }
    int res = good.size();
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    int n, x;
    for (int i=0; i<T; ++i) {
        cin >> n >> x;
        res[i] = solve(n, x);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}