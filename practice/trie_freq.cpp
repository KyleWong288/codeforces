#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll n;

// unordered_map sparse, less memory than vector
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

// counts the number of strings with matching prefix
ll count(Node* root, string& s) {
    ll res = 0;
    Node* cur = root;
    for (int i=0; i<s.size(); ++i) {
        int ch = s[i];
        if (cur->next.find(ch) == cur->next.end()) {
            break;
        }
        cur = cur->next[ch];
        res += cur->freq;
    }
    return res;
}