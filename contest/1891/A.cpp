#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// break into chunks of differences of powers of 2, these chunks must be non-decreasing
int solution(vector<int>& v) {
    vector<int> diffs = {1};
    int m = 1;
    int msum = 1;
    while (msum+m <= N) {
        msum += m;
        diffs.push_back(m);
        m *= 2;
    }
    int p=0;
    for (auto& diff : diffs) {
        for (int i=p+1; i<p+diff; ++i) {
            if (v[i] < v[i-1]) {
                return 0;
            }
        }
        p += diff;
    }
    ++p;
    while (p < N) {
        if (v[p] < v[p-1]) {
            return 0;
        }
        ++p;
    }
    return 1;
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
        if (r) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}