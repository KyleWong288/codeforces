#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// we need to know when to switch from neg to pos, use two dp (track best neg and best pos)
// dp[i] = min # of ops to make [0:i] sorted and end on a neg/pos value
// for neg, this ending value is arbitrarily small so it doesn't matter the actual value
// for pos, this ending value is arbitrarily big so it doesn't matter the actual value
int solution(vector<int>& a) {
    vector<int> dpNeg(N, 0);
    vector<int> dpPos(N, 0);
    dpNeg[0] = 1;
    for (int i=1; i<N; ++i) {
        if (a[i] < a[i-1]) {
            dpNeg[i] = dpNeg[i-1];
            dpPos[i] = min(dpNeg[i-1], dpPos[i-1] + 1);
        }
        else if (a[i] > a[i-1]) {
            dpNeg[i] = dpNeg[i-1] + 1;
            dpPos[i] = min(dpNeg[i-1], dpPos[i-1]);
        }
        else {
            dpNeg[i] = dpNeg[i-1] + 1;
            dpPos[i] = min(dpNeg[i-1], dpPos[i-1] + 1);
        }
    }
    int res = min(dpNeg[N-1], dpPos[N-1]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> a(N);
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