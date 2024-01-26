#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll n;

struct Node {
    unordered_map<char, Node*> next;
    int freq = 0;
    Node() {
        
    }
};

void build(Node* root, string& s) {
    Node* cur = root;
    for (int i=0; i<s.size(); ++i) {
        char ch = s[i];
        if (cur->next.find(ch) == cur->next.end()) {
            cur->next[ch] = new Node();
        }
        cur = cur->next[ch];
        cur->freq++;
    }
}

ll count(Node* root, string& s) {
    ll res = 0;
    Node* cur = root;
    for (int i=s.size()-1; i>=0; --i) {
        int ch = s[i];
        if (cur->next.find(ch) == cur->next.end()) {
            break;
        }
        cur = cur->next[ch];
        res += cur->freq;
    }
    return res;
}

// simplify, what is an O(n) way to count base lengths? (n * len[i]) + sum(lens)
// how do collapses affect? collapses subtracts two chars. so final is (n*len[i]) + sum(lens) - 2*collapses
// how to count collapses on a certain string s? use a frequency trie and count the number of strings whose prefix matches the suffix of s
ll solve(vector<string>& strings) {
    ll res = 0;
    ll lenAll = 0;
    for (auto& s : strings) {
        lenAll += s.size();
    }
    // construct frequency trie:
    Node* root = new Node();
    for (auto& s : strings) {
        build(root, s);
    }
    // subtract suffix/prefix matches:
    for (auto& s : strings) {
        ll matches = count(root, s);
        res += lenAll + (n * s.size()) - matches * 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<string> strings(n);
    for (auto& x : strings) {
        cin >> x;
    }
    cout << solve(strings) << endl;
    return 0;
}