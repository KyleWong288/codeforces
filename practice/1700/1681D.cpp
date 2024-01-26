#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

// bfs? this is too brute force, estimated tc is between O(2^n) and O(8^n)
// HOW IS THIS FAST????
int solution(ll n, ll x) {
    int res = 0;
    map<ll, bool> vis;
    queue<ll> q;
    vis[x] = 1;
    q.push(x);
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            ll cur = q.front();
            q.pop();
            // get length and digits
            ll num = cur;
            ll len = 0;
            vector<bool> digits(10, 0);
            while (num) {
                int d = num % 10;
                digits[d] = 1;
                ++len;
                num /= 10;
            }
            if (len == n) {
                return res;
            }
            for (int d=2; d<=9; ++d) {
                if (digits[d]) {
                    ll next = cur * d;
                    if (vis[next] == 0) {
                        vis[next] = 1;
                        q.push(next);
                    }
                }
            }
        }
        ++res;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll n, x;
    cin >> n >> x;
    cout << solution(n, x) << endl;
    return 0;
}