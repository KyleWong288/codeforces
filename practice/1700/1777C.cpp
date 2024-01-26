#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_set>
#include <cmath>
using namespace std;

int N, M;

// stores the set of divisors for each value in [1, 1e5]
vector<unordered_set<int>> divs;

// each n has O(sqrt(n)) divisors, construct the set of divisors for each n
// sort A, make a sliding window that is valid only if the union of divisor sets is [1, m], find min endpt diff
int solution(vector<int>& v) {
    int res = 1e9;
    sort(v.begin(), v.end());
    vector<int> freq(M+1, 0);
    int cnt = 0;
    int l = 0;
    int r = 0;
    while (l < N) {
        // move r
        while (r < N && cnt < M) {
            for (auto& div : divs[v[r]]) {
                if (div <= M) {
                    if (freq[div] == 0) {
                        ++cnt;
                    }
                    freq[div]++;
                }
            }
            ++r;
        }
        if (cnt >= M) {
            res = min(res, v[r-1] - v[l]);
        }
        // move l
        for (auto& div : divs[v[l]]) {
            if (div <= M) {
                freq[div]--;
                if (freq[div] == 0) {
                    --cnt;
                }
            }
        }
        ++l;
    }
    if (res == 1e9) {
        return -1;
    }
    return res;
}

int main() {
    // precompute divisor sets
    divs.resize(1e5+1);
    for (int i=1; i<=1e5; ++i) {
        int end = sqrt(i);
        for (int j=1; j<=end; ++j) {
            if (i % j == 0) {
                divs[i].insert(j);
                divs[i].insert(i/j);
            }
        }
    }
    // test cases
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<int> v(N);
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