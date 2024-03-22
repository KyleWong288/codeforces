#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;


// array looks like: [0 ... 0, modval ... modval, endval ... endval], k can be at most 3
// k = 1: endval is 0
// k = 2: [0... 0, endval ... endval] -> any value in [1,N-1] and any value modN = 0
// k = 3: any value > N and modN != 0
// lots of edge cases
int solution(int N, int M, int K) {
    if (K == 1) {
        return 1;
    }
    else if (K == 2) {
        if (M <= N) {
            return M;
        }
        return N - 1 + (M / N);
    }
    else if (K == 3) {
        if (M == 0 || M == 1 || M <= N) {
            return 0;
        }
        return M - (M / N) - (N - 1);
    }
    else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, N, M, K;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M >> K;
        res[i] = solution(N, M, K);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}