#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

int N;

// 0s and dupes always work
// simplify problem: what if we could create b of size n+1 instead of n? easy: 0, pref[1], pref[2] ... pref[n]
// so how can we erase one index in b? if we can construct the same sum twice, we will have a duplicate value in b which we can drop 
// say we have two subset sums of 9: naively we do [0,2,6,9] and [0,1,9], but we can merge and do [0,1,2,6,9]
int solution(vector<int>& a) {
    set<int> sums;
    int end = (1 << N);
    for (int b=0; b<end; ++b) {
        int sum = 0;
        for (int i=0; i<N; ++i) {
            if ((b >> i) & 1) {
                sum += a[i];
            }
        }
        if (sums.find(sum) != sums.end()) {
            return 1;
        }
        sums.insert(sum);
    }
    return 0;
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
        cout << (r ? "YES\n" : "NO\n");
    }
    return 0;
}