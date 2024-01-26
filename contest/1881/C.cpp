#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// match the 4 corresponding pts, move them up to the max char
int solution(vector<string>& mat) {
    int res = 0;
    for (int i=0; i<N/2; ++i) {
        int end = N-i-1;
        for (int j=i; j<end; ++j) {
            // cout << "comparing:" << endl;
            // cout << i << " " << j << endl;
            // cout << j << " " << end << endl;
            // cout << end << " " << end-j+i << endl;
            // cout << end-j+i << " " << i << endl;
            char c1 = mat[i][j];
            char c2 = mat[j][end];
            char c3 = mat[end][end-j+i];
            char c4 = mat[end-j+i][i];
            char high = max(max(c1, c2), max(c3, c4));
            res += (high - c1) + (high - c2) + (high - c3) + (high - c4);
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
        vector<string> v(N);
        for (auto& row : v) {
            cin >> row;
        }
        res[i] = solution(v);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}