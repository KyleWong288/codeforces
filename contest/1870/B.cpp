#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N, M;

// first get base xor of a
// min: Even, bits get cleared so OR with everything. Odd, bits get set so OR with nothing.
// max: Even, bits get cleared so OR with nothing. Odd, bits get set so OR with everything.
pair<int,int> solution(vector<int>& a, vector<int>& b) {
    int base = 0;
    int min, max;
    for (auto& x : a) {
        base ^= x;
    }
    if (a.size() % 2) { // odd case
        min = base;
        max = base;
        for (auto& x : b) {
            max |= x;
        }
    }
    else { // even case
        min = base;
        int remove = 0;
        for (auto& x : b) {
            remove |= x;
        }
        min |= remove;
        min ^= remove;
        max = base;
    }
    return {min, max};
}

int main() {
    int t;
    cin >> t;
    vector<pair<int,int>> res(t);
    for (int i=0; i<t; ++i) {
        cin >> N >> M;
        vector<int> a(N);
        vector<int> b(M);
        for (auto& x : a) {
            cin >> x;
        }
        for (auto& x : b) {
            cin >> x;
        }
        res[i] = solution(a, b);
    }
    for (auto& r : res) {
        cout << r.first << " " << r.second << endl;
    }
    return 0;
}