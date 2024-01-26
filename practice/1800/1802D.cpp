#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// given all the A gifts and B gifts seen so far, gets the smallest diff between their maxes
int getMaxDiff(vector<int>& a, vector<int>& b, vector<int>& buyAs, vector<int>& buyBs) {
    int res = 1e9;
    int szA = buyAs.size();
    int szB = buyBs.size();
    if (buyAs[szA-1] == buyBs[szB-1]) {
        if (szA > 1) {
            int va = a[buyAs[szA-2]];
            int vb = b[buyBs[szB-1]];
            res = min(res, abs(va - vb));
        }
        if (szB > 1) {
            int va = a[buyAs[szA-1]];
            int vb = b[buyBs[szB-2]];
            res = min(res, abs(va - vb));
        }
    }
    else {
        int va = a[buyAs[szA-1]];
        int vb = b[buyBs[szB-1]];
        res = abs(va - vb);
    }
    return res;
}

// gifts that aren't m1 or m2 don't matter, just make sure that each store is visited
// separate into a[i] and b[i], sort and then sliding window to track visited store ids
// min diff is found between consecutive a[i] & b[i] in sorted order
// edge case: what if consecutive a[i] and b[i] are from same store? look one extra back
int solution(vector<int>& a, vector<int>& b) {
    // gifts stores <cost, index, a or b>
    vector<vector<int>> gifts(2*N);
    for (int i=0; i<N; ++i) {
        gifts[2*i] = {a[i], i, 1};
        gifts[2*i+1] = {b[i], i, 2};
    }
    // visit all stores:
    sort(gifts.begin(), gifts.end());
    vector<int> freq(N, 0);
    // stores indicies of bought gifts
    vector<int> buyAs;
    vector<int> buyBs;
    int stores = 0;
    int res = 1e9;
    for (int i=0; i<gifts.size(); ++i) {
        int idx = gifts[i][1];
        int type = gifts[i][2];
        if (freq[idx] == 0) {
            ++stores;
        }
        freq[idx]++;
        type == 1 ? buyAs.push_back(idx) : buyBs.push_back(idx);
        if (stores == N && buyAs.size() && buyBs.size()) {
            res = min(res, getMaxDiff(a, b, buyAs, buyBs));
        }
    }
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
        vector<int> b(N);
        for (int j=0; j<N; ++j) {
            cin >> a[j] >> b[j];
        }
        res[i] = solution(a, b);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}