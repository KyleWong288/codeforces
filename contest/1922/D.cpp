#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_set>
using namespace std;
typedef long long ll;

int N;

struct Node {
    Node* prev = nullptr;
    Node* next = nullptr;
    int atk;
    int def;
    int dmg = 0;
    Node(int a, int d) {
        atk = a;
        def = d;
    }
};

// we need to splice and then reconnect neighbors -> its giving LRU cache -> doubly linked list
// each node can be deleted at most once, and updating neighbors and checking for new deletions is O(1)
void solution(vector<int>& a, vector<int>& d) {
    vector<int> res(N);
    // build the DLL:
    Node* head = new Node(a[0], d[0]);
    Node* tail = head;
    Node* cur;
    for (int i=1; i<N; ++i) {
        cur = new Node(a[i], d[i]);
        tail->next = cur;
        cur->prev = tail;
        tail = cur;
    }
    // initialize set of nodes to delete:
    unordered_set<Node*> del;
    cur = head;
    while (cur) {
        if (cur->prev) cur->dmg += cur->prev->atk;
        if (cur->next) cur->dmg += cur->next->atk;
        if (cur->dmg > cur->def) {
            del.insert(cur);
        }
        cur = cur->next;
    }
    // simulate splices:
    for (int i=0; i<N; ++i) {
        res[i] = del.size();
        unordered_set<Node*> nextDel;
        for (auto& m : del) {
            Node* l = m->prev;
            Node* r = m->next;
            if (l) {
                l->dmg -= m->atk;
                l->next = m->next;
                if (l->next) {
                    l->dmg += l->next->atk;
                }
                // we changed his damage, so update accordingly
                if (l->dmg > l->def && del.find(l) == del.end()) {
                    nextDel.insert(l);
                }
                if (l->dmg <= l->def && nextDel.find(l) != nextDel.end()) {
                    nextDel.erase(l);
                }
            }
            if (r) {
                r->dmg -= m->atk;
                r->prev = m->prev;
                if (r->prev) {
                    r->dmg += r->prev->atk;
                }
                // we changed his damage, so update accordingly
                if (r->dmg > r->def && del.find(r) == del.end()) {
                    nextDel.insert(r);
                }
                if (r->dmg <= r->def && nextDel.find(r) != nextDel.end()) {
                    nextDel.erase(r);
                }
            }
        }
        del = nextDel;
    }
    for (auto& r : res) {
        cout << r << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        cin >> N;
        vector<int> a(N);
        vector<int> d(N);
        for (auto& x : a) {
            cin >> x;
        }
        for (auto& x : d) {
            cin >> x;
        }
        solution(a, d);
    }
    return 0;
}