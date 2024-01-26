#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// worst case scenario for i: we go to the other endpoint, and then go to i
// i is left of start s: s->n then s->i, so we need a[i]+(n-i-1) damage
// i is right of start s: s->0 then s->i, so we need a[i]+i damage
// what idx to start? brute force, track the prefix max to left and suffix max to right
int solve(vector<int>& a) {
    if (N == 1) { return a[0]; }
    vector<int> maxL(N);
    maxL[0] = a[0] + (N-1);
    for (int i=1; i<N; ++i) {
        maxL[i] = max(maxL[i-1], a[i] + (N-i-1));
    }
    vector<int> maxR(N);
    maxR[N-1] = a[N-1] + (N-1);
    for (int i=N-2; i>=0; --i) {
        maxR[i] = max(maxR[i+1], a[i] + i);
    }
    int startL = max(a[0], maxR[1]);
    int startR = max(a[N-1], maxL[N-2]);
    int res = min(startL, startR);
    for (int i=1; i<N-1; ++i) {
        int cur = max(max(maxL[i-1], maxR[i+1]), a[i]);
        res = min(res, cur);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    vector<int> a(N);
    for (auto& x : a) {
        cin >> x;
    }
    cout << solve(a) << endl;
    return 0;
}