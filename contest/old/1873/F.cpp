#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N, K;

// sliding window lmao
// two conditions for adding to window: empty window (i == j) or divisible, but both need to follow K limit
// r stops getting pushed once divisiblity fails, so l can catch up
int solution(vector<int>& A, vector<int>& H) {
    int res = 0;
    int l = 0;
    int r = 0;
    int sum = 0;
    while (l < N) {
        if (r < l) {
            r = l;
            sum = 0;
        }
        while (r < N && ((l == r) || H[r-1] % H[r] == 0) && sum + A[r] <= K) {
            sum += A[r++];
        }
        res = max(res, r - l);
        sum -= A[l++];
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
        vector<int> A(N);
        vector<int> H(N);
        for (auto& x : A) {
            cin >> x;
        }
        for (auto& x : H) {
            cin >> x;
        }
        res[i] = solution(A, H);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}