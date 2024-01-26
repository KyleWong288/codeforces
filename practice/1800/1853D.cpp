#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// sorted b values correspond to sorted a values
// there is some eventual split between negatives (left part) and positives (right part)
// if b[i] is pos: i cant fall in the first n - a[i] indices
// if b[i] is neg: i must fall in the first n - a[i] indices
// b[i] is neg: a[i] means there are a[i] pos vals with higher abs val
// easy way to assign is to use each value from [1, n] once, either as pos or neg
void solution(vector<int>& a) {
    // stores <a[i], i>
    vector<pair<int,int>> prs(N);
    for (int i=0; i<N; ++i) {
        prs[i] = {a[i], i};
    }
    sort(prs.begin(), prs.end());
    // assign negs and right most pos in b vector:
    vector<int> b(N+1, 0);
    b[0] = -1e9;
    int l = 1, r = N, cur = N;
    for (auto& pr : prs) {
        int ai = pr.first;
        if (b[l] || l > N - ai) {
            break;
        }
        else {
            while (ai > N - r) {
                b[r--] = cur--;
            }
            b[l++] = -1 * cur--;
        }
    }
    // assign remaining pos in b vector:
    while (r >= 0 && b[r] == 0) {
        b[r--] = cur--;
    }
    // verify b works:
    for (int i=1; i<=N; ++i) {
        int ai = prs[i-1].first;
        int len = lower_bound(b.begin(), b.end(), -1 * b[i]) - b.begin() - 1;
        if (ai + len != N) {
            cout << "NO" << endl;
            return;
        }
    }
    // rearrange the sorted b vector:
    vector<int> res(N);
    for (int i=0; i<N; ++i) {
        int idx = prs[i].second;
        res[idx] = b[i+1];
    }
    cout << "YES" << endl;
    for (auto& r : res) {
        cout << r << " ";
    }
    cout << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        solution(a);
    }
    return 0;
}