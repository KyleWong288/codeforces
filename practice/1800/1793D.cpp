#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;
typedef long long ll;

int N;

// approach: for each possible mex, find the range of subarrays with that mex in p and q, then get overlap
// in the overlapping subarray, any (l,r) pair works, so just len choose 2
// build subarray with 2 ptrs moving outwards, mex+1 always includes the subarray of mex
ll solution(vector<int>& p, vector<int>& q) {
    ll res = 0;
    unordered_map<int,int> idxP;
    unordered_map<int,int> idxQ;
    for (int i=0; i<N; ++i) {
        idxP[p[i]] = i;
        idxQ[q[i]] = i;
    }
    // mex = 1:

    // regular case:
    int lp = (min_element(p.begin(), p.end()) - p.begin());
    int lq = (min_element(q.begin(), q.end()) - q.begin());
    int rp = lp;
    int rq = lq;
    for (int i=2; i<=N; ++i) {
        int lpNew = min(lp, idxP[i]);
        int rpNew = max(rp, idxP[i]);
        int lqNew = min(lq, idxQ[i]);
        int rqNew = max(rq, idxQ[i]);
        
        if (lpNew < lp) {

        }
        else if (rpNew > rp) {

        }

        // update bounding array for p:
        lp = min(lp, idxP[i]);
        rp = max(rp, idxP[i]);
        // update bounding array for q:
        lq = min(lq, idxQ[i]);
        rq = max(rq, idxQ[i]);

    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    vector<int> p(N);
    vector<int> q(N);
    for (auto& x : p) {
        cin >> x;
    }
    for (auto& x : q) {
        cin >> x;
    }
    cout << solution(p, q) << endl;
    return 0;
}