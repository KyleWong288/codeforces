#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N, K;

// answer always uses the max number of purchases -> K / c, where c is cheapest coin
// start by spamming c, then greedily shift as many as possible to the next longest purchase
void solution(vector<int>& v) {
    // create monoinc stack of relevant coins, stores <cost, index in v>
    vector<pair<int,int>> coins;
    for (int i=0; i<N; ++i) {
        while (!coins.empty() && coins.back().first >= v[i]) {
            coins.pop_back();
        }
        coins.push_back({v[i], i});
    }
    int cap = K / coins[0].first;
    // compute how much of each coin to buy based on shifts
    vector<int> buys(coins.size(), 0);
    buys[0] = cap;
    int sum = cap * coins[0].first;
    for (int i=1; i<coins.size(); ++i) {
        int diff = coins[i].first - coins[i-1].first;
        int remain = K - sum;
        int shift = min(remain / diff, buys[i-1]);
        buys[i-1] -= shift;
        buys[i] += shift;
        sum += (diff * shift);
        if (shift == 0) { break; }
    }
    // fill out res by tracking cumulative losses
    vector<int> loss(N+1, 0);
    for (int i=0; i<coins.size(); ++i) {
        int idx = coins[i].second;
        loss[idx+1] = buys[i];
    }
    for (int i=1; i<=N; ++i) {
        loss[i] += loss[i-1];
    }
    vector<int> res(N);
    for (int i=0; i<N; ++i) {
        res[i] = cap - loss[i];
    }
    for (auto& x : res) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> v(N);
        for (auto& x : v) {
            cin >> x;
        }
        cin >> K;
        solution(v);
    }
    return 0;
}