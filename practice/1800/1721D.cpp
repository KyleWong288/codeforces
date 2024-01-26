#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// for each bit, computes new partition and if it is takeable or not
// could just use a loop ngl
void dfs(vector<vector<int>>& partsA, vector<vector<int>>& partsB, vector<bool>& levels, int bit) {
    if (bit < 0) {
        return;
    }
    bool use = 1;
    vector<vector<int>> newA;
    vector<vector<int>> newB;
    for (int p=0; p<partsA.size(); ++p) {
        vector<int> a0, a1, b0, b1;
        for (int i=0; i<partsA[p].size(); ++i) {
            int va = partsA[p][i], vb = partsB[p][i];
            if ((va >> bit) & 1) {
                a1.push_back(va);
            }
            else {
                a0.push_back(va);
            }
            if ((vb >> bit) & 1) {
                b1.push_back(vb);
            }
            else {
                b0.push_back(vb);
            }
        }
        if (a0.size() == b1.size()) {
            newA.push_back(a0);
            newA.push_back(a1);
            newB.push_back(b1);
            newB.push_back(b0);
        }
        else {
            use = 0;
            break;
        }
    }
    if (use) {
        dfs(newA, newB, levels, bit-1);
    }
    else {
        levels[bit] = 0;
        dfs(partsA, partsB, levels, bit-1);
    }
}

// d&c, recursively partition based on if bit is set/unset
// for a given bit b, if cnt(1) in set a == cnt(0) in set b, this bit can be set in the entire partition
// all partitions that cover bit b need to be matchable, so dfs needs to track all parts
ll solution(vector<int>& a, vector<int>& b) {
    vector<bool> levels(32, 1);
    // parts contains a list of values for each partition
    vector<vector<int>> partsA;
    vector<vector<int>> partsB;
    partsA.push_back(a);
    partsB.push_back(b);
    dfs(partsA, partsB, levels, 31);
    ll res = 0;
    for (int i=0; i<32; ++i) {
        if (levels[i]) {
            res += (1LL << i);
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
        cin >> N;
        vector<int> a(N);
        vector<int> b(N);
        for (auto& x : a) {
            cin >> x;
        }
        for (auto& x : b) {
            cin >> x;
        }
        res[i] = solution(a, b);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}