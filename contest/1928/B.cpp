#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

int N;

// sort, find largest # of unique vals in [l,r], where window value diff is n
int solve(vector<int>& a) {
    int res = 0;
    sort(a.begin(), a.end());
    map<int,int> freq;
    int l = 0;
    for (int r=0; r<N; ++r) {
        freq[a[r]]++;
        // move left:
        while (a[r] - a[l] + 1 > N) {
            freq[a[l]]--;
            if (freq[a[l]] == 0) {
                freq.erase(a[l]);
            }
            ++l;
        }
        res = max(res, (int)freq.size());
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
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}