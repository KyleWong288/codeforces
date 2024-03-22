#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// you just care about top 3 in each
int solution(vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& c) {
    int res = 0;
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                if (a[i][1] == b[j][1] || b[j][1] == c[k][1] || a[i][1] == c[k][1]) {
                    continue;
                }
                res = max(res, a[i][0] + b[j][0] + c[k][0]);
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<vector<int>> a(N, vector<int>(3, 0));
        vector<vector<int>> b(N, vector<int>(3, 1));
        vector<vector<int>> c(N, vector<int>(3, 2));
        for (int i=0; i<N; ++i) {
            cin >> a[i][0];
            a[i][1] = i;
        }
        for (int i=0; i<N; ++i) {
            cin >> b[i][0];
            b[i][1] = i;
        }
        for (int i=0; i<N; ++i) {
            cin >> c[i][0];
            c[i][1] = i;
        }
        res[i] = solution(a,b,c);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}