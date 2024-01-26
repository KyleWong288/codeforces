#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, Q;

// classic get base score and for each query compute some small update
// changing result only affects later results, at most log(n)
// going backwards (last round -> first round) has nice parent/child index mapping (par is i, children are 2i+1, 2i+2)
void solution(string& s, vector<pair<int,char>>& queries) {
    vector<int> res(Q);
    reverse(s.begin(), s.end());
    int l, r;
    // get base dp:
    vector<int> dp(N, 0);
    for (int i=N-1; i>=0; --i) {
        l = 2*i+2, r = 2*i+1;
        if (s[i] == '0') {
            l < N ? dp[i] = dp[l] : dp[i] = 1;
        }
        else if (s[i] == '1') {
            r < N ? dp[i] = dp[r] : dp[i] = 1;
        }
        else {
            r < N ? dp[i] = dp[l] + dp[r] : dp[i] = 2;
        }
    }
    // answer queries:
    for (int i=0; i<Q; ++i) {
        int idx = N - queries[i].first;
        char ch = queries[i].second;
        s[idx] = ch;
        l = 2*idx+2, r = 2*idx+1;
        if (ch == '0') {
            l < N ? dp[idx] = dp[l] : dp[idx] = 1;
        }
        else if (ch == '1') {
            r < N ? dp[idx] = dp[r] : dp[idx] = 1;
        }
        else {
            r < N ? dp[idx] = dp[l] + dp[r] : dp[idx] = 2;
        }
        while (idx > 0) {
            idx = (idx - 1) / 2;
            l = 2*idx+2, r = 2*idx+1;
            if (s[idx] == '0') {
                l < N ? dp[idx] = dp[l] : dp[idx] = 1;
            }
            else if (s[idx] == '1') {
                r < N ? dp[idx] = dp[r] : dp[idx] = 1;
            }
            else {
                l < N ? dp[idx] = dp[l] + dp[r] : dp[idx] = 2;
            }
        }
        res[i] = dp[0];
    }
    for (auto& r : res) {
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int k;
    string s;
    cin >> k >> s >> Q;
    N = s.size();
    vector<pair<int,char>> queries(Q);
    for (auto& q : queries) {
        cin >> q.first >> q.second;
    }
    solution(s, queries);
    return 0;
}