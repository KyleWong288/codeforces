#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M;

// 4 way greedily match with 2 ptrs in a and b
ll solution(vector<ll>& a, vector<ll>& b) {
    ll res = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int l = 0, r = M-1;
    int la = 0, ra = N-1;
    while (la <= ra) {
        ll diff1 = abs(a[la] - b[l]);
        ll diff2 = abs(a[la] - b[r]);
        ll diff3 = abs(a[ra] - b[l]);
        ll diff4 = abs(a[ra] - b[r]);
        ll high = max(max(diff1, diff2), max(diff3, diff4));
        if (high == diff1) {
            ++la;
            ++l;
        }
        else if (high == diff2) {
            ++la;
            --r;
        }
        else if (high == diff3) {
            --ra;
            ++l;
        }
        else {
            --ra;
            --r;
        }
        res += high;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<ll> a(N);
        vector<ll> b(M);
        for (auto& x : a) {
            cin >> x;
        }
        for (auto& x : b) {
            cin >> x;
        }
        res[i] = solution(a, b);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}