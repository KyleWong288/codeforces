#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, K;

// modulo of product is product of modulos
// for k = {2, 3, 5} just bump up the highest modulo to k
// special case for k = 4, either make 4 or two 2s
int solution(vector<int>& v) {
    int high = 0;
    vector<int> freq(6, 0);
    for (auto& x : v) {
        if (x % K == 0) {
            return 0;
        }
        high = max(high, x % K);
        freq[x % K]++;
    }
    if (K != 4) {
        return K - high;
    }
    // special case for 4
    if (freq[2] >= 2) {
        return 0;
    }
    if (freq[2] == 1 && freq[1] >= 1) {
        return 1;
    }
    if (freq[3] >= 1) {
        return 1;
    }
    if (freq[1] >= 2) {
        return 2;
    }
    return K - high;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
        vector<int> v(N);
        for (auto& x : v) {
            cin >> x;
        }
        res[i] = solution(v);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}