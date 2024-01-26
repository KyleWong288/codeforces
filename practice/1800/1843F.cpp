#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

struct Node {
    int diffP = 0;
    int diffN = 0;
    int sumP = 0;
    int sumN = 0;
    int curSum = 0;
};

// use prefix sum to track the largest pos diff and largest neg diff, k can be in this range
// each node tracks: largest pos diff, largest neg diff, largest pos psum, largest neg psum, current psum
// when adding a new node, just update based on parent values
void solution(vector<vector<int>>& queries) {
    vector<bool> res;
    vector<Node> nodes(N+2);
    Node root;
    root.diffP = 1;
    root.sumP = 1;
    root.curSum = 1;
    nodes[1] = root;
    int id = 1;
    for (auto& q : queries) {
        // update:
        if (q.size() == 2) {
            Node par = nodes[q[0]];
            Node cur;
            cur.curSum = par.curSum + q[1];
            cur.sumP = max(par.sumP, cur.curSum);
            cur.sumN = min(par.sumN, cur.curSum);
            cur.diffP = max(par.diffP, cur.curSum - cur.sumN);
            cur.diffN = min(par.diffN, cur.curSum - cur.sumP);
            nodes[++id] = cur;
        }
        // query:
        else {
            Node v = nodes[q[1]];
            if (q[2] >= v.diffN && q[2] <= v.diffP) {
                res.push_back(1);
            }
            else {
                res.push_back(0);
            }
        }
    }
    for (auto r : res) {
        cout << (r ? "YES\n" : "NO\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    char op;
    int a, b, c;
    while (T--) {
        cin >> N;
        vector<vector<int>> queries(N);
        for (int i=0; i<N; ++i) {
            cin >> op;
            if (op == '+') {
                cin >> a >> b;
                queries[i] = {a, b};
            }
            else {
                cin >> a >> b >> c;
                queries[i] = {a, b, c};
            }
        }
        solution(queries);
    }
    return 0;
}