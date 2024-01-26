#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M;

ll count(vector<int>& a, vector<int>& b) {
    ll cnt = 0;
    int p1 = 0;
    int p2 = 0;
    while (p2 < N) {
        while (p2 < N && b[p2] <= a[p1]) {
            ++p2;
        }
        if (p2 >= N) { break; }
        ++cnt;
        ++p1;
        ++p2;
    }
    return N - cnt;
}

// let s be the base score when m = 1
// since only one index is changed, we will at most have to delete one extra element, our score will either be s+1 or s
// theres a pivot point where score changes from s to s+1, find this pivot via binary search
ll solution(vector<int>& a, vector<int>& b) {
    ll cnt = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll s = count(a, b);
    int l = 2;
    int r = M;
    while (l <= r) {
        int m = (l + r) / 2;
        vector<int> v = a;
        v[0] = m;
        sort(v.begin(), v.end());
        ll score = count(v, b);
        if (score == s) {
            l = m+1;
        }
        else {
            r = m-1;
        }
    }
    ll res = (s * r) + (s+1) * (M - r);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<int> a(N);
        a[0] = 1;
        for (int j=1; j<N; ++j) {
            cin >> a[j];
        }
        vector<int> b(N);
        for (int j=0; j<N; ++j) {
            cin >> b[j];
        }
        res[i] = solution(a, b);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}