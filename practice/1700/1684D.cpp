#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

int N, K;

// use a heap to store the best k jumps
// don't worry about jumps affecting future values: for k jumps, we always overcount by k choose 2 no matter what indices jumps are
// jump saves a[i] but adds 1 to everything right -> a[i] - (N - i), since N is constant we get a[i] + i
ll solution(vector<ll>& a) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    for (int i=0; i<N; ++i) {
        pq.push({a[i] + i, i});
        if (pq.size() > K) {
            pq.pop();
        }
    }
    vector<bool> jump(N, 0);
    while (pq.size()) {
        int idx = pq.top().second;
        jump[idx] = 1;
        pq.pop();
    }
    ll res = 0;
    ll jumpCnt = 0;
    for (int i=0; i<N; ++i) {
        if (jump[i]) {
            ++jumpCnt;
        }
        else {
            res += a[i] + jumpCnt;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
        vector<ll> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solution(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}