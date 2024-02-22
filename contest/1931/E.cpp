#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

int n, m;

int cntTrail(int x) {
    int res = 0;
    while (x) {
        if (x % 10 == 0) {
            ++res;
            x /= 10;
        }
        else {
            break;
        }
    }
    return res;
}

int cntDigits(int x) {
    int res = 0;
    while (x) {
        ++res;
        x /= 10;
    }
    return res;
}

int chopTrail(int x) {
    int trail = cntTrail(x);
    while (trail--) {
        x /= 10;
    }
    return x;
}

struct Compare {
    bool operator()(const int& l, const int& r) {
        return cntTrail(l) < cntTrail(r);
    }
};

// total digit len can never increase, and only decreases via leading 0s
// Sasha wants to maximize (preserve digits), Anna wants to minimize (erase digits)
// Sort by dec number of trailing zeroes
int solve(vector<int>& a) {
    priority_queue<int, vector<int>, Compare> pq;
    int total = 0;
    for (auto& x : a) {
        total += cntDigits(x);
        pq.push(x);
    }
    int lose = 0;
    for (int i=0; i<n; ++i) {
        // Anna tries to chop 0s
        int top = pq.top();
        pq.pop();
        int trail = cntTrail(top);
        int next = chopTrail(top);
        lose += trail;
        pq.push(next);
        // Sasha tries to concatenate [trailing 0s] [anything]
        // dont need to actually concat, we basically just save the [trailing 0s] num and erase from pq
        pq.pop();
    }
    return ((total - lose) > m);
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> m;
        vector<int> a(n);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solve(a);
    }
    for (auto& r : res) {
        cout << (r ? "Sasha\n" : "Anna\n");
    }
    return 0;
}