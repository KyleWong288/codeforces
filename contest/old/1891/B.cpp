#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;

int N, Q;

// get the first occurence of each power of 2 in q
// each a[i] can only be affected by a power of 2 at most once
void solution(vector<ll>& a, vector<int>& q) {
    vector<ll> res(N);
    vector<bool> found(31, 0);
    vector<int> pows;
    for (auto& x : q) {
        if (!found[x]) {
            pows.push_back(x);
            found[x] = 1;
        }
    }
    for (int i=0; i<N; ++i) {
        int cur = a[i];
        for (auto& exp : pows) {
            int p = pow(2, exp);
            if (cur % p == 0) {
                cur += (p / 2);
            }
        }
        res[i] = cur;
    }
    for (auto& x : res) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        vector<int> q(Q);
        for (auto& x : q) {
            cin >> x;
        }
        solution(a, q);
    }
    return 0;
}