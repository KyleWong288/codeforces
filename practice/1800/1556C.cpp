#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// RBS think +/- balance, visualize the balance graph
// for a fixed open a[i], how many can you take from a fixed close a[i]?: min balance in range - max(start bal, end bal)
// brute force over each fixed open and fixed close -> O(n^2)
ll solution(vector<ll>& a) {
    ll res = 0;
    vector<ll> balance(N+1, 0);
    for (int i=0; i<N; ++i) {
        if (i % 2) {
            balance[i+1] = balance[i] - a[i];
        }
        else {
            balance[i+1] = balance[i] + a[i];
        }
    }
    for (int i=0; i<N-1; i+=2) {
        ll low = balance[i+1];
        for (int j=i+1; j<N; ++j) {
            low = min(low, balance[j]);
            if (j % 2) {
                res += max(0LL, low - max(balance[i], balance[j+1]) + 1);
            }
        }
        // we always overcount by 1 on the first (i, i+1)
        --res;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    vector<ll> a(N);
    for (auto& x : a) {
        cin >> x;
    }
    cout << solution(a) << endl;
    return 0;
}