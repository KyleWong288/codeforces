#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

// brute force
int solution(int a, int b, int xk, int yk, int xq, int yq) {
    int res = 0;
    int x, y;
    set<pair<int,int>> takeK;
    set<pair<int,int>> takeQ;
    vector<int> dr = {a, a, -1*a, -1*a, b, b, -1*b, -1*b};
    vector<int> dc = {b, -1*b, b, -1*b, a, -1*a, a, -1*a};
    for (int m=0; m<8; ++m) {
        y = yk + dr[m];
        x = xk + dc[m];
        takeK.insert({x, y});
        y = yq + dr[m];
        x = xq + dc[m];
        takeQ.insert({x,y});
    }
    for (auto& pr : takeK) {
        if (takeQ.find(pr) != takeQ.end()) {
            ++res;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int a, b, xk, yk, xq, yq;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> a >> b >> xk >> yk >> xq >> yq;
        res[i] = solution(a, b, xk, yk, xq, yq);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}