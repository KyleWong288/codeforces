#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

int N, M;

// dijkstra but use a 2d distance array: the bike used to get to the vertex is an extra dimension
ll solution(vector<vector<ll>>& adj, vector<ll>& speeds) {
    // dist[i][j] = min time from 1 to i, where we land on i with bike j
    vector<vector<ll>> dist(N+1, vector<ll>(N+1, 1e18));
    dist[1][1] = 0;
    // stores <time, node id, bike id that lead to cur>
    priority_queue<vector<ll>, vector<vector<ll>>, greater<>> pq;
    pq.push({0, 1, 1});
    while (pq.size()) {
        ll curDist = pq.top()[0];
        ll cur = pq.top()[1];
        ll prevBike = pq.top()[2];
        pq.pop();
        if (dist[cur][prevBike] < curDist) { continue; }
        for (int to=1; to<=N; ++to) {
            if (adj[cur][to] == 1e18) { continue; }
            ll nextDist1 = curDist + speeds[prevBike] * adj[cur][to];
            if (nextDist1 < dist[to][prevBike]) {
                pq.push({nextDist1, to, prevBike});
                dist[to][prevBike] = nextDist1;
            }
            ll nextDist2 = curDist + speeds[cur] * adj[cur][to];
            if (nextDist2 < dist[to][cur]) {
                pq.push({nextDist2, to, cur});
                dist[to][cur] = nextDist2;
            }
        }
    }
    ll res = 1e18;
    for (int i=1; i<=N; ++i) {
        res = min(res, dist[N][i]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    ll u, v, w;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<vector<ll>> adj(N+1, vector<ll>(N+1, 1e18));
        for (int j=0; j<M; ++j) {
            cin >> u >> v >> w;
            w = min(adj[u][v], w);
            adj[u][v] = w;
            adj[v][u] = w;
        }
        vector<ll> speeds(N+1);
        for (int j=1; j<=N; ++j) {
            cin >> speeds[j];
        }
        res[i] = solution(adj, speeds);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}