#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// visualize the prefix sum graph!!!
// k should always be some actual prefix sum value, shouldn't be lower since we just lose more
// shouldn't be higher since this is only meaningful if we can reach that value, so we'll just use that value when we get there 
// our final sum looks like: (prefix sum with k) (portion flattened to k) (useful suffix sum)
// flattened portion: subarray sum starting after the prefix is negative
// useful suffix portion: suffix sum S such that S > abs(min suffix sum to right)
ll solution(vector<ll>& a) {
    // compute where the useful suffix portions are:
    vector<bool> use(N+1, 0);
    use[N] = 1;
    vector<ll> suff(N+1, 0);
    ll sum = 0;
    ll low = 2e18;
    for (int i=N-1; i>=0; --i) {
        sum += a[i];
        low = min(low, sum);
        suff[i] = sum;
        use[i] = ((a[i] > 0) && (sum >= abs(low)));
    }
    for (auto x: use) {
        cout << x << " ";
    }
    cout << endl;
    for (auto x: suff) {
        cout << x << " ";
    }
    cout << endl;
    // go through each prefix sum:
    int p = 0;
    sum = 0;
    while (p < N && !use[p]) ++p;
    ll res = sum + suff[p];
    ll bestK = 0;
    for (int i=0; i<N; ++i) {
        sum += a[i];
        p = max(p, i+1);
        while (p < N && !use[p]) ++p;
        if (sum + suff[p] > res) {
            res = sum + suff[p];
            bestK = sum;
        }
    }
    return bestK;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
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