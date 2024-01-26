#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int R, G, B;
vector<ll> red;
vector<ll> green;
vector<ll> blue;
// dp[i][j][k] = max area when we have used i red, j green, k blue
vector<vector<vector<ll>>> dp;

ll dfs(int r, int g, int b) {
    // base case is if 2 channels are taken:
    if ((r == R) + (g == G) + (b == B) >= 2) {
        return 0;
    }
    // cache case:
    if (dp[r][g][b]) {
        return dp[r][g][b];
    }
    // regular case:
    ll rg = 0, rb = 0, gb = 0;
    if (r < R && g < G) {
        rg = red[r] * green[g] + dfs(r+1, g+1, b);
    }
    if (r < R && b < B) {
        rb = red[r] * blue[b] + dfs(r+1, g, b+1);
    }
    if (g < G && b < B) {
        gb = green[g] * blue[b] + dfs(r, g+1, b+1);
    }
    dp[r][g][b] = max(rg, max(rb, gb));
    return dp[r][g][b];
}

// if we had 2 colors, greedily pair large in color1 with large in color2
// greedy only works for 2 since we know which 2 to pick from
// still have this greedy idea of pairing largest, so dp over channel pairs
// bottom up dp since we want to know the best way to work with the remaining pairs
void solution() {
    dp.resize(R+1, vector<vector<ll>>(G+1, vector<ll>(B+1, 0)));
    sort(red.rbegin(), red.rend());
    sort(green.rbegin(), green.rend());
    sort(blue.rbegin(), blue.rend());
    ll res = dfs(0, 0, 0);
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> R >> G >> B;
    red.resize(R);
    green.resize(G);
    blue.resize(B);
    for (auto& x : red) {
        cin >> x;
    }
    for (auto& x : green) {
        cin >> x;
    }
    for (auto& x : blue) {
        cin >> x;
    }
    solution();
    return 0;
}