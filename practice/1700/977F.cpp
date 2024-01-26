#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;
typedef long long ll;

// par[a[i]] is index of first occurence of a[i+1] after i (least recently found)
// track par to track longest consecutive ssq
void solution(vector<int>& a, int N) {
    int len = 0;
    // maps <value, index in a>
    unordered_map<int,int> lrf;
    vector<int> lis(N, 0);
    vector<int> par(N, -1);
    for (int i=N-1; i>=0; --i) {
        if (lrf.find(a[i]+1) != lrf.end()) {
            int parIdx = lrf[a[i]+1];
            lis[i] = lis[parIdx] + 1;
            par[i] = parIdx;
        }
        else {
            lis[i] = 1;
        }
        lrf[a[i]] = i;
        len = max(len, lis[i]);
    }
    vector<int> seq;
    for (int i=0; i<N; ++i) {
        if (lis[i] != len) { continue; }
        int cur = i;
        while (cur != -1) {
            seq.push_back(cur);
            cur = par[cur];
        }
        break;
    }
    cout << len << endl;
    for (auto& x : seq) {
        cout << x+1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> a(N);
    for (auto& x : a) {
        cin >> x;
    }
    solution(a, N);
    return 0;
}