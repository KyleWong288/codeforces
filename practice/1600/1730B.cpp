#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <iomanip>
#include <cmath>
using namespace std;

const double STEP = 0.0000001;
const double EPS = 0.00000001;
int N;

// checks if v1 < v2 using epsilon
bool lessThan(double& v1, double& v2) {
    return ((v2 - v1) >= EPS);
}

// checks if v1 == v2 using epsilon
bool equalTo(double& v1, double& v2) {
    return (abs(v1 - v2) <= EPS);
}

// binary search on x and check the max time it would take for any person, valley finding but with yucky floats
double solution(vector<pair<int,int>>& v) {
    double l = 0;
    double r = 1e9;
    double m, mL, mR, maxM, maxL, maxR;
    while (l <= r) {
        m = (l + r) / 2;
        mL = m - STEP;
        mR = m + STEP;
        maxM = 0, maxL = 0, maxR = 0;
        for (auto& pr : v) {
            maxM = max(maxM, abs(m - pr.first) + pr.second);
            maxL = max(maxL, abs(mL - pr.first) + pr.second);
            maxR = max(maxR, abs(mR - pr.first) + pr.second);
        }
        if (equalTo(maxL, maxM) && equalTo(maxM, maxR)) { // valley
            return m;
        }
        else if (lessThan(maxL, maxM)) { // lesser on left
            r = m-STEP;
        }
        else { // less on right
            l = m+STEP;
        }
    }
    return m;
}

int main() {
    cout << setprecision(10);
    int T;
    cin >> T;
    vector<double> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<pair<int,int>> v(N);
        for (auto& x : v) {
            cin >> x.first;
        }
        for (auto& x : v) {
            cin >> x.second;
        }
        res[i] = solution(v);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}