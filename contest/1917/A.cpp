#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// if neg exists, do one change if product is pos, else do zero changes
// if no neg exists, do one change to 0
// if zero exist, always zero
void solve(vector<ll>& a) {
    int neg = -1;
    int cntNeg = 0;
    int cntZero = 0;
    for (int i=0; i<N; ++i) {
        cntNeg += (a[i] < 0);
        cntZero += (a[i] == 0);
        if (a[i] < 0) {
            neg = i+1;
        }
    }
    if (cntZero) {
        cout << 0 << endl;
        return;
    }
    if (cntNeg) {
        if (cntNeg % 2) {
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
            cout << neg << " " << 0 << endl;
        }
    }
    else {
        cout << 1 << endl;
        cout << 1 << " " << 0 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        solve(a);
    }
    return 0;
}