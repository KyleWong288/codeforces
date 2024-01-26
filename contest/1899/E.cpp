#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;
typedef long long ll;

int N;

// once we hit the min element, we can no longer do operations, so if we have anything unsorted after the min, we fail
// else, res is index of min element
int solution(vector<int>& a) {
    int minV = a[0];
    int minI = 0;
    for (int i=1; i<N; ++i) {
        if (a[i] < minV) {
            minV = a[i];
            minI = i;
        }
    }
    for (int i=minI; i<N-1; ++i) {
        if (a[i] > a[i+1]) {
            return -1;
        }
    }
    return minI;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        res[i] = solution(a);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}