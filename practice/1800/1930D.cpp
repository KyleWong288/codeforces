#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// greedily construct q: if p[i] needs a 1, set q[i+1] to 1 and q[i] to 0
// if we go l->r, then we want to bias our 1s to the right so they're closer to the remaining indexes
// abuses how the mode allows 10 and 01 to work
int solve(string& s) {
    int res = 0;
    for (int i=0; i<N; ++i) {
        int cnt = 0;
        vector<bool> q(N, 0);
        for (int j=i; j<N; ++j) {
            if (s[j] == '1') {
                if (!((j && q[j-1]) || q[j])) {
                    int next = min(N-1, j+1);
                    q[next] = 1;
                    ++cnt;
                }
            }
            res += cnt;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    string s;
    for (int i=0; i<T; ++i) {
        cin >> N >> s;
        res[i] = solve(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}