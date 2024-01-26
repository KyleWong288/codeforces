#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, Q;

// partition arr into chunks of non-increasing subarrays with len >= 2
// for each non-inc subarray, we take largest (left) and smallest (right), remove the rest -> guaranteed to be valid
// score = len of range - # of bad indices in range, use psum & range query to count bad indices
// normal range query: ps[r+1] - ps[l]
// modified range query: ps[r+1] - ps[l+2] <- +2 since the first 2 are always safe
void solution(vector<int>& a, vector<pair<int,int>>& queries) {
    vector<int> res(Q);
    vector<int> psum(N+1, 0);
    for (int i=2; i<N; ++i) {
        psum[i+1] = psum[i];
        if (a[i-2] >= a[i-1] && a[i-1] >= a[i]) {
            psum[i+1]++;
        }
    }
    for (int q=0; q<Q; ++q) {
        int l = queries[q].first - 1;
        int r = queries[q].second - 1;
        int len = r - l + 1;
        int lose = psum[r+1] - psum[l+2];
        if (len < 3) {
            res[q] = len;
        }
        else {
            res[q] = len - lose;
        }
    }
    for (auto& r : res) {
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> Q;
    vector<int> a(N);
    for (auto& x : a) {
        cin >> x;
    }
    vector<pair<int,int>> queries(Q);
    for (auto& pr : queries) {
        cin >> pr.first >> pr.second;
    }
    solution(a, queries);
    return 0;
}