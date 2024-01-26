#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int n, f, a, b;

// greedy, if (difference between adj times * a) > b, turn off and on
int solution(vector<int>& times) {
    ll use = f;
    for (int i=1; i<=n; ++i) {
        ll diff = times[i] - times[i-1];
        if (diff * a > b) {
            use -= b;
        }
        else {
            use -= diff * a;
        }
    }
    return (use > 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> n >> f >> a >> b;
        vector<int> times(n+1);
        for (int j=1; j<=n; ++j) {
            cin >> times[j];
        }
        res[i] = solution(times);
    }
    for (auto& r : res) {
        cout << (r ? "YES\n" : "NO\n");
    }
    return 0;
}