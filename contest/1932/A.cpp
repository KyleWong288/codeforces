#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int n;

int solve(vector<int>& a) {
    int res = 0;
    for (int i=0; i<n; ++i) {
        if (i < n-1 && a[i] == -1 && a[i+1] == -1) break;
        if (a[i] == 1) res++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n;
        vector<int> a(n);
        cin >> s;
        for (int j=0; j<n; ++j) {
            if (s[j] == '.') {
                a[j] = 0;
            }
            else if (s[j] == '@') {
                a[j] = 1;
            }
            else {
                a[j] = -1;
            }
        }
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}