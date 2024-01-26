#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

int N, M;

// convert binary string to int
int binary(string& s) {
    int res = 0;
    int b = 0;
    for (int i=0; i<N; ++i) {
        if (s[i] == '1') {
            res += (1 << (N - i - 1));
        }
    }
    return res;
}

// computes the next state, given the input and output of the medicine
int nextState(int cur, int in, int out) {
    int res = 0;
    for (int i=0; i<N; ++i) {
        int b = ((cur >> i) & 1);
        if ((in >> i) & 1) {
            b = 0;
        }
        if ((out >> i) & 1) {
            b = 1;
        }
        res += (b << i);
    }
    return res;
}

// find shortest weighted path from start state to end state of all 0s -> obvious dijkstra
// vertices are states of symptoms (2^n states), edges are medicine
// how do we know which edge to take? take all of them -> O(m)
// O(2^n) states, we enumerate over O(m) edges for each
int solution(vector<vector<int>>& edges, int start) {
    vector<int> dist((1 << N), 1e9);
    dist[start] = 0;
    // pq stores <dist, cur state>
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, start});
    while (pq.size()) {
        int curDist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (cur == 0) {
            return curDist;
        }
        if (dist[cur] < curDist) { continue; }
        // edges store <weight, in, out>
        for (auto& e : edges) {
            int next = nextState(cur, e[1], e[2]);
            int nextDist = curDist + e[0];
            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, d;
    cin >> T;
    vector<int> res(T);
    string s, t;
    for (int i=0; i<T; ++i) {
        cin >> N >> M >> s;
        int start = binary(s);
        vector<vector<int>> edges(M, vector<int>(3));
        for (int j=0; j<M; ++j) {
            cin >> d >> s >> t;
            edges[j][0] = d;
            edges[j][1] = binary(s);
            edges[j][2] = binary(t);
        }
        res[i] = solution(edges, start);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}