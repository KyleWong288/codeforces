#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, Q;

void solution(vector<ll>& q, vector<vector<int>>& queries) {
    vector<ll> res(Q);

    for (auto& r : res) {
        cout << r << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        vector<ll> a(N+1);
        for (int i=1; i<=N; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> queries(Q, vector<int>(3));
        for (auto& q : queries) {
            cin >> q[0] >> q[1] >> q[2];
        }
        solution(a, queries);
    }
    return 0;
}