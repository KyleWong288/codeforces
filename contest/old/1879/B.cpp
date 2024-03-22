#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <numeric>
using namespace std;
typedef long long ll;

int N;

// row optimized: pair each row val with smallest col val
// col optimized: pair each col val with smallest row val
ll solution(vector<ll>& A, vector<ll>& B) {
    ll sumA = accumulate(A.begin(), A.end(), 0LL);
    ll sumB = accumulate(B.begin(), B.end(), 0LL);
    ll lowA = *min_element(A.begin(), A.end());
    ll lowB = *min_element(B.begin(), B.end());
    ll res = min(sumA + N * lowB, sumB + N * lowA);
    return res;
}

int main() {
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<ll> A(N);
        vector<ll> B(N);
        for (auto& x : A) {
            cin >> x;
        }
        for (auto& x : B) {
            cin >> x;
        }
        res[i] = solution(A, B);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}