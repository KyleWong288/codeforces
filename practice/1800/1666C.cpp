#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;

// find the bounding box of all points, the actual score is width + height of bounding box
// case 1: colinear, easy sort
// case 2: triangle, one point has a middle x val, one point has a middle y val, centroid = (mid x, mid y)
// then, just connect the centroid to the triange vertices
void solution() {
    vector<ll> p1(2);
    vector<ll> p2(2);
    vector<ll> p3(2);
    cin >> p1[0] >> p1[1] >> p2[0] >> p2[1] >> p3[0] >> p3[1];
    vector<ll> xs = {p1[0], p2[0], p3[0]};
    vector<ll> ys = {p1[1], p2[1], p3[1]};
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    vector<ll> c = {xs[1], ys[1]};
    // (cx, cy) to (px, py) requires lines (cx, cy)->(cx, py) and (cx, py)->(px, py)
    vector<vector<ll>> pts(6);
    pts[0] = {c[0], c[1], c[0], p1[1]};
    pts[1] = {c[0], p1[1], p1[0], p1[1]};
    pts[2] = {c[0], c[1], c[0], p2[1]};
    pts[3] = {c[0], p2[1], p2[0], p2[1]};
    pts[4] = {c[0], c[1], c[0], p3[1]};
    pts[5] = {c[0], p3[1], p3[0], p3[1]};
    // ignore singletons:
    int single = 0;
    for (auto& p : pts) {
        single += (p[0] == p[2] && p[1] == p[3]);
    }
    cout << 6 - single << endl;
    for (auto& p : pts) {
        if (p[0] == p[2] && p[1] == p[3]) {
            continue;
        }
        cout << p[0] << " " << p[1] << " " << p[2] << " " << p[3] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solution();
    return 0;
}