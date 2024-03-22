#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
#include <iomanip>
using namespace std;

const double STEP = 0.0000001;
const double EPS = 0.00000001;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2));
}

// checks if d1 > d2
bool geq(double d1, double d2) {
    return (d1 - d2) >= EPS;
}

// lazy binary search on w
// works when: both points in one circle, one point in each circle and the circles overlap
double solution(int px, int py, int ax, int ay, int bx, int by) {
    double l = 0;
    double r = 4096;
    double distAO = dist(0, 0, ax, ay);
    double distAP = dist(px, py, ax, ay);
    double distBO = dist(0, 0, bx, by);
    double distBP = dist(px, py, bx, by);
    double distOverlap = dist(ax, ay, bx, by) / 2;
    while (geq(r, l)) {
        double m = (l + r) / 2;
        bool OInA = geq(m, distAO);
        bool PInA = geq(m, distAP);
        bool OInB = geq(m, distBO);
        bool PInB = geq(m, distBP);
        bool overlapAB = geq(m, distOverlap);
        if ( (OInA && PInA) || (OInB && PInB) ||
             (OInA && PInB && overlapAB) ||
             (PInA && OInB && overlapAB) ) {
                r = m - STEP;
        }
        else {
            l = m + STEP;
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << setprecision(10);
    int T, px, py, ax, ay, bx, by;
    cin >> T;
    vector<double> res(T);
    for (int i=0; i<T; ++i) {
        cin >> px >> py >> ax >> ay >> bx >> by;
        res[i] = solution(px, py, ax, ay, bx, by);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}