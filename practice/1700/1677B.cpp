#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M;

// rows: partition into consecutive blocks of size m
// cols: partition into spaced seqeuences, where the distance between items is m
// track rows: use dp by looking at prev row (dp[i-m])
// track cols: once the earliest good student in the spaced seq is hit, that column will always be set
void solution(string& s) {
    int end = N*M;
    // get row vals:
    // dp[i] = # of set rows when adding the ith student
    // dp[i] = dp[i-m] + {is there a 1 from [i-m+1, i]}
    vector<int> dp(end, 0);
    int cnt = 0;
    for (int i=0; i<end; ++i) {
        cnt += (s[i] == '1');
        if (i - M < 0) {
            dp[i] = (cnt > 0);
        }
        else {
            cnt -= (s[i-M] == '1');
            dp[i] = dp[i-M] + (cnt > 0);
        }
    }
    // get col vals:
    cnt = 0;
    vector<int> colCnt(end, 0);
    vector<bool> colSet(M, 0);
    for (int i=0; i<end; ++i) {
        int col = i % M;
        if (s[i] == '1' && !colSet[col]) {
            ++cnt;
            colSet[col] = 1;
        }
        colCnt[i] = cnt;
    }
    for (int i=0; i<end; ++i) {
        cout << dp[i] + colCnt[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    while (T--) {
        cin >> N >> M >> s;
        solution(s);
    }
    return 0;
}