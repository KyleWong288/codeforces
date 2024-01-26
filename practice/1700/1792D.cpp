#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M;

struct Node {
    vector<Node*> children;
    int depth;
    bool vis;
    Node(int m, int d) {
        children.resize(m+1, nullptr);
        depth = d;
        vis = 0;
    }
};

// p is the order, q is the base values
// two initial ways to approach, one good and one bad
// 1 (bad): treat each a[i] as order, say a[1] = 2, lookup if q with a 1 in the second position exists, hard to lookup since positions can be arbitrary
// 2 (good): treat each a[i] as value, say a[3] = 1, lookup if p with a 3 in the first position exists, easy to lookup with trie since positions are sequential
// each node in trie stores if it can be reached, highest depth is answer
void solution(vector<vector<int>>& perms) {
    // build trie:
    Node* root = new Node(M, 0);
    root->vis = 1;
    for (auto& p : perms) {
        Node* cur = root;
        for (int i=0; i<M; ++i) {
            int x = p[i];
            if (cur->children[x] == nullptr) {
                cur->children[x] = new Node(M, i+1);
            }
            cur = cur->children[x];
        }
    }
    // mark visitable nodes in trie:
    for (auto& p : perms) {
        Node* cur = root;
        vector<int> order(M+1);
        for (int i=0; i<M; ++i) {
            order[p[i]] = i+1;
        }
        for (int i=1; i<=M; ++i) {
            int x = order[i];
            if (cur->children[x] == nullptr) {
                break;
            }
            cur = cur->children[x];
            cur->vis = 1;
        }
    }
    // get depths for each perm:
    vector<int> res(N);
    for (int i=0; i<N; ++i) {
        Node* cur = root;
        for (int j=0; j<M; ++j) {
            int x = perms[i][j];
            if (!cur->children[x]->vis) {
                break;
            }
            cur = cur->children[x];
        }
        res[i] = cur->depth;
    }
    for (auto& x : res) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        vector<vector<int>> perms(N, vector<int>(M));
        for (auto& perm : perms) {
            for (auto& x : perm) {
                cin >> x;
            }
        }
        solution(perms);
    }
    return 0;
}