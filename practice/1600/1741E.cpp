#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N;

struct state {
    bool szR = 0;   // can i be a right size
    bool end = 0;   // can i be the end of a subarray
};

// left size: If i-1 is a right size or end of a subarray, i can be a left size. This means i + nums[i] can be an end of a subarray
// right size: If i-nums[i]-1 is a right size or end of subarray, i can be a right size
int solution(vector<int>& v) {
    vector<state> dp(N);
    // base case, try i=0 as a left size
    if (v[0] < N) {
        dp[v[0]].end = 1;
    }
    for (int i=1; i<N; ++i) {
        int prev = i - v[i] - 1;
        int next = i + v[i];
        // see if i can be a left size
        if (dp[i-1].szR || dp[i-1].end) {
            if (next < N) {
                dp[next].end = 1;
            }
        }
        // see if i can be a right size
        if (prev == -1 || (prev >= 0 && (dp[prev].szR || dp[prev].end))) {
            dp[i].szR = 1;
        }
    }
    int res = dp[N-1].szR || dp[N-1].end;
    return res;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> v(N);
        for (auto& x : v) {
            cin >> x;
        }
        res[i] = solution(v);
    }
    for (auto& r : res) {
        if (r) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}