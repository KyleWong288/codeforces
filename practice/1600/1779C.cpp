#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

int N, M;

// split into left (0:m] and right [m+1:n)
// right prefix sum never wants to be negative, erase biggest neg
// left suffix sum never wants to be positive, erase biggest pos
int solution(vector<ll>& v) {
    M--;
    int res = 0;
    // get right:
    priority_queue<ll, vector<ll>, greater<>> minHeap; // only stores neg
    ll pref = 0;
    for (int i=M+1; i<N; ++i) {
        if (v[i] < 0) {
            minHeap.push(v[i]);
        }
        pref += v[i];
        if (pref < 0) {
            ll num = minHeap.top();
            minHeap.pop();
            pref -= 2 * num;
            ++res;
        }
    }
    // get left:
    priority_queue<ll> maxHeap; // only stores pos
    ll suff = 0;
    for (int i=M; i>0; --i) {
        if (v[i] > 0) {
            maxHeap.push(v[i]);
        }
        suff += v[i];
        if (suff > 0) {
            ll num = maxHeap.top();
            maxHeap.pop();
            suff -= 2 * num;
            ++res;
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<ll> v(N);
        for (auto& x : v) {
            cin >> x;
        }
        res[i] = solution(v);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}