#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, K;

// if a[x] = x and we left shift by x, then x ends up at a[n]
// work backwards: start at position n, right shift by a[n], compute new value at a[n]
// fails if our current a[n] > n (this means it can't be a fixed point in the previous array state)
int solution(vector<int>& a) {
    vector<bool> vis(N+1, 0);
    int i = N;
    int steps = 0;
    while (true) {
        if (steps == K) { // enough steps
            return 1;
        }
        if (vis[i]) { // cycle
            return 1;
        }
        if (a[i] > N) { // fail case
            return 0;
        }
        ++steps;
        vis[i] = 1;
        i = (i - a[i] + N) % N;
        if (i == 0) {
            i = N;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
        vector<int> a(N+1);
        for (int j=1; j<=N; ++j) {
            cin >> a[j];
        }
        res[i] = solution(a);
    }
    for (auto& r : res) {
        if (r) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}