#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M;

void solve(vector<int>& a, string& s) {
    vector<int> res(N);
    ll prod = 1;
    vector<int> idxs;
    int l = 0;
    int r = N-1;
    for (auto& ch : s) {
        if (ch == 'L') {
            idxs.push_back(l++);
        }
        else {
            idxs.push_back(r--);
        }
    }
    for (int i=N-1; i>=0; --i) {
        int idx = idxs[i];
        prod = prod * a[idx] % M;
        res[i] = prod;
    }
    for (auto& r : res) {
        cout << r << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    while(T--) {
        cin >> N >> M;
        vector<int> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        cin >> s;
        solve(a, s);
    }
    return 0;
}