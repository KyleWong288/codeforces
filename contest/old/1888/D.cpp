#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M;

// sort a and b and two pointers
// match each element in a with the smallest larger number in b
int solution(vector<int>& a, vector<int>& b) {
    int res = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int p1 = 0;
    int p2 = 0;
    while (p2 < N) {
        while (p2 < N && b[p2] <= a[p1]) {
            ++p2;
        }
        if (p2 >= N) { break; }
        ++res;
        ++p1;
        ++p2;
    }
    return N - res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        vector<int> a(N);
        a[0] = 1;
        for (int j=1; j<N; ++j) {
            cin >> a[j];
        }
        vector<int> b(N);
        for (int j=0; j<N; ++j) {
            cin >> b[j];
        }
        res[i] = solution(a, b);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}