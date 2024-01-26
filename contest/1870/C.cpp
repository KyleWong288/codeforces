#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

// symmetric matrix, always forms a square with length len (L, R)
// L = earliest index with val geq than cur, R = latest index with val geq than cur
// store the prefix/suffix max and binary search to find L and R
void solution(vector<int>& v) {
    int l, m, r, xL, xR;
    vector<int> res(K+1, 0);
    vector<int> pref(N, 0);
    vector<int> suff(N, 0);
    // make pref:
    pref[0] = v[0];
    for (int i=1; i<N; ++i) {
        pref[i] = max(pref[i-1], v[i]);
    }
    // make suff:
    suff[N-1] = v[N-1];
    for (int i=N-2; i>=0; --i) {
        suff[i] = max(suff[i+1], v[i]);
    }
    // find L and R for each x:
    for (auto& x : v) {
        // bs pref for L
        l = 0;
        r = N-1;
        while (l <= r) {
            m = (l + r) / 2;
            if (pref[m] < x) {
                l = m+1;
            }
            else {
                r = m-1;
            }
        }
        xL = l;
        // bs suff for R
        l = 0;
        r = N-1;
        while (l <= r) {
            m = (l + r) / 2;
            if (suff[m] < x) {
                r = m-1;
            }
            else {
                l = m+1;
            }
        }
        xR = r;
        res[x] = 2 * (xR - xL + 1);
    }
    for (int i=1; i<=K; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<int> v(N);
        for (auto& x : v) {
            cin >> x;
        }
        solution(v);
    }
    return 0;
}