#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// n is even: use the range [n - n/2, n + n/2], ignore center n and make left right pairs
// proof: each pair sums to 2n, we have n/2 pairs, so we get a sum of n^2. Our sum is n^2 and our range is n.
// n is odd: use the range [4n - n, 4n + n], use the center 4n and make left right pairs
// proof: each pair sums to 8n, we have floor(n/2) pairs, and we have the center of 4n, so we get a sum of 4n^2. Our sum is 4n^2 and our range is 2n.
void solution(int n) {
    if (n % 2 == 0) {
        int l = n - n/2;
        int r = n + n/2;
        for (int i=l; i<=r; ++i) {
            if (i != n) {
                cout << i << " ";
            }
        }
    }
    else {
        int l = 4 * n - n;
        int r = 4 * n + n;
        for (int i=0; i<n/2; ++i) {
            cout << l << " " << r << " ";
            ++l;
            --r;
        }
        cout << 4*n;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        solution(N);
    }
    return 0;
}