#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

// takes at most p additions (we cycle through all digits in the last digit)
// if the last digit is d: lookup if d-1, d-2 ... exist, first one to not exist is bottleneck
// edge case where d cycles to 0, which can cause a cascade addition previous digits
ll solution(vector<int>& a, int n, int p) {
    set<int> have;
    for (auto& x : a) {
        have.insert(x);
    }
    // check if we need a cascade (d cycles to 0):
    bool cascade = 0;
    int d = a[n-1];
    for (int i=0; i<=min(d, n+1); ++i) {
        if (have.find(i) == have.end()) {
            cascade = 1;
        }
    }
    // if we have a cascade, add any new digits to have:
    if (cascade) {
        vector<int> b = a;
        for (int i=n-2; i>=0; --i) {
            b[i] += 1;
            if (b[i] != p) {
                have.insert(b[i]);
                break;
            }
        }
        if (b[0] == p || b.size() == 1) {
            have.insert(1);
        }
    }
    // find the first missing bottleneck:
    int firstMissing = d;
    if (cascade) {
        firstMissing = 0;
    }
    for (int i=1; i<=min(p, n+1); ++i) {
        int x = (d - i + p) % p;
        if (have.find(x) == have.end()) {
            firstMissing = x;
            break;
        }
    }
    int res = 0;
    if (firstMissing == d) {
        res = 0;
    }
    else if (firstMissing < d) {
        res = (p - d) + firstMissing;
    }
    else {
        res = firstMissing - d;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, N, P;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> P;
        vector<int> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solution(a, N, P);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}