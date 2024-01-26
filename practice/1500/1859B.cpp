#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N, M, D;

// least we can go is base-1, most we can go is base
// try removing seller i, then see if the cookies between i+1 and i-1 is less than before
pair<int,int> solution(vector<int>& v) {
    // handle start case
    int base = 1;
    if (v[0] != 1) {
        v.insert(v.begin(), 1);
    }
    // handle normal case
    for (int i=1; i<v.size(); ++i) {
        ++base;
        base += (v[i] - v[i-1] - 1) / D;
    }
    // handle end case
    base += (N - v.back()) / D;
    // track if we can go lesser
    int freq = 0;
    for (int i=1; i<v.size()-1; ++i) {
        int oldC = (v[i] - v[i-1] - 1) / D + (v[i+1] - v[i] - 1) / D + 2;
        int newC = (v[i+1] - v[i-1] - 1) / D + 1;
        if (newC < oldC) {
            ++freq;
        }
    }
    // handle end case
    int m = v.size();
    int oldC = (N - v[m-1]) / D + (v[m-1] - v[m-2] - 1) / D + 1;
    int newC = (N - v[m-2]) / D;
    if (newC < oldC) {
        ++freq;
    }
    if (freq == 0) {
        return {base, M};
    }
    return {base - 1, freq};
}

int main() {
    int T;
    cin >> T;
    vector<pair<int,int>> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M >> D;
        vector<int> v(M);
        for (auto& x : v) {
            cin >> x;
        }
        res[i] = solution(v);
    }
    for (auto& r : res) {
        cout << r.first << " " << r.second << endl;
    }
    return 0;
}