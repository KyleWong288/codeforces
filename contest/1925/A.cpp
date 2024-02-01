#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// just spam the first k chars n times
string solve(int n, int k) {
    string res = "";
    for (int i=0; i<n; ++i) {
        for (int j=0; j<k; ++j) {
            char ch = 'a' + j;
            res += ch;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int n, k;
    vector<string> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> k;
        res[i] = solve(n, k);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}