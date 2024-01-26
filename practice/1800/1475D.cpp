#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

int N, M;

// split based on b[i] = 1 or 2, always use large to small in each
// greedy doesn't work: If highest val in 2 < sum of highest two vals in 1, do we pop from 1 or 2? Theres no optimal choice
// create psums, brute force on how many to take in 1, then bs to find the complement in 2
ll solution(vector<ll>& a, vector<ll>& b) {
    vector<ll> v1, v2;
    for (int i=0; i<N; ++i) {
        b[i] == 1 ? v1.push_back(a[i]) : v2.push_back(a[i]);
    }
    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());
    vector<ll> ps1(v1.size()+1, 0);
    vector<ll> ps2(v2.size()+1, 0);
    for (int i=0; i<v1.size(); ++i) {
        ps1[i+1] = ps1[i] + v1[i];
    }
    for (int i=0; i<v2.size(); ++i) {
        ps2[i+1] = ps2[i] + v2[i];
    }
    int res = 1e9;
    for (int i=0; i<ps1.size(); ++i) {
        ll diff = M - ps1[i];
        int j = lower_bound(ps2.begin(), ps2.end(), diff) - ps2.begin();
        if (j < ps2.size() && ps1[i] + ps2[j] >= M) {
            res = min(res, i + 2 * j);
        }
    }
    if (res == 1e9) {
        res = -1;
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
        for (auto& x : a) {
            cin >> x;
        }
        vector<ll> b(N);
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