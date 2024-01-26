#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

int N;

// graph between numbers and unique prime factors is the only feasible size (each number has at most log(n) prime factors)
// for each spider, assign it to all of its prime factors, and assign each of its prime factor to that spider
// run a simple bfs to find sssp
void solution(vector<int>& a, int s, int t) {
    // stores the list of prime factors for each number with sieve
    vector<vector<int>> pfacts(N+1);
    for (int i=2; i<=N; ++i) {
        if (pfacts[i].empty()) {
            for (int j=i+i; j<=N; j+=i) {
                pfacts[j].push_back(i);
            }
            pfacts[i].push_back(i);
        }
    }
    // indices [0, N] are for prime factors, indicies [N+1, 2N] are for spiders
    vector<vector<int>> adj(2*N+1);
    for (int i=0; i<a.size(); ++i) {
        int spider = a[i];
        int spIdx = i + 1 + N;
        for (auto& pf : pfacts[spider]) {
            adj[spIdx].push_back(pf);
            adj[pf].push_back(spIdx);
        }
    }
    s += N;
    t += N;
    // bfs:
    int res = 0;
    vector<bool> vis(2*N+1, 0);
    vis[s] = 1;
    vector<int> par(2*N+1, 0);
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        ++res;
        int sz = q.size();
        while (sz--) {
            int cur = q.front();
            q.pop();
            // reconstruct the path:
            if (cur == t) {
                vector<int> path;
                while (cur != 0) {
                    path.push_back(cur);
                    cur = par[cur];
                }
                reverse(path.begin(), path.end());
                // t is prime
                if (path.size() % 2 == 0) {
                    path.push_back(t + N);
                }
                cout << (path.size() / 2 + 1) << endl;
                for (int i=0; i<path.size(); i+=2) {
                    cout << path[i] - N << " ";
                }
                cout << endl;
                return;
            }
            for (auto& to : adj[cur]) {
                if (!vis[to]) {
                    q.push(to);
                    vis[to] = 1;
                    par[to] = cur;
                }
            }
        }
    }
    cout << -1 << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    vector<int> a(N);
    for (auto& x : a) {
        cin >> x;
    }
    N = 300000;
    int s, t;
    cin >> s >> t;
    solution(a, s, t);
    return 0;
}