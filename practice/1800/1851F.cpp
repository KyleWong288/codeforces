#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N, K;
int i1, i2, x, best;

// computes the optimal value of x given nums[i] and nums[j]
int getX(int v1, int v2) {
    int res = 0;
    long long pow = 1;
    for (int i=0; i<K; ++i) {
        int b1 = v1 & 1;
        int b2 = v2 & 1;
        if (b1 == b2) {
            if (b1) { // if bit is set, add a 0 bit
                res += 0;
            }
            else { // if bit is not set, add a 1 bit
                res += pow;
            }
        }
        pow *= 2;
        v1 = v1 >> 1;
        v2 = v2 >> 1;
    }
    return res;
}

// d&c array based on matching bits, start at most sig
// base case is when d&c subarray has 2 numbers, find max over these
// check the special case for dupes
void solution(vector<pair<int,int>>& v, int shift) {
    if (v.size() < 2) {
        return;
    }
    if (v.size() == 2 || v[0].first == v[1].first) {
        int a = v[0].first;
        int b = v[1].first;
        int newX = getX(a, b);
        int newVal = ((a ^ newX) & (b ^ newX));
        if (newVal > best) {
            best = newVal;
            i1 = v[0].second;
            i2 = v[1].second;
            x = newX;
        }
        return;
    }
    if (shift < 0) {
        return;
    }
    vector<pair<int,int>> v0; // not set
    vector<pair<int,int>> v1; // is set
    for (auto& pr : v) {
        if ((pr.first >> shift) & 1) {
            v1.push_back(pr);
        }
        else {
            v0.push_back(pr);
        }
    }
    solution(v0, shift-1);
    solution(v1, shift-1);
}

int main() {
    int T;
    cin >> T;
    vector<vector<int>> res(T, vector<int>(3));
    for (int i=0; i<T; ++i) {
        best = -1;
        cin >> N >> K;
        // stores <val, idx>
        vector<pair<int,int>> v(N);
        for (int j=0; j<N; ++j) {
            cin >> v[j].first;
            v[j].second = j;
        }
        solution(v, K-1);
        res[i][0] = i1+1;
        res[i][1] = i2+1;
        res[i][2] = x;
    }
    for (auto& r : res) {
        cout << r[0] << " " << r[1] << " " << r[2] << endl;
    }
    return 0;
}