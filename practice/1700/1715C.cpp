#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

ll N, M;

// get base score: get sum starting at index l, subtract 1 as we move right and losing a chunk subtracts 1 from all right endpts
// case 1 (xyz -> xxz): -(i-1) * (n-i+1), left ends = [1, i-1], right ends = [i, N]
// case 2 (xyz -> xzz): -(i) * (n-i), left ends = [1, i], right ends = [i+1, N]
// case 3 (xyy -> xxy): (n-i+1) - (i), starting on i gets +1, ending on i gets -1, containing i has same score
// case 4 (xxy -> xyy): (i) - (n-i+1), starting on i gets -1, ending on i gets +1, containing i has same score
// case 5 (xxx -> xyx): - 2lr - l - r, where l = (i-1), r = (n-i), starting on i gets -1, ending on i gets -1, containing i gets -2
// reversals for (1,2,5) is just adding, also ignore no changes
void solution(vector<ll>& a, vector<pair<int,int>>& queries) {
    // get base score:
    ll sum = 0;
    ll blocks = 0;
    for (int i=1; i<=N; ++i) {
        if (a[i] != a[i-1]) {
            ++blocks;
        }
        sum += blocks;
    }
    ll base = sum;
    for (int i=2; i<=N; ++i) {
        --sum;
        if (a[i] != a[i-1]) {
            sum -= (N - i + 1);
        }
        base += sum;
    }
    // process queries:
    vector<ll> res(M);
    for (int q=0; q<M; ++q) {
        ll i = queries[q].first;
        int x = queries[q].second;
        if (a[i-1] != a[i+1]) {
            if (a[i] == a[i-1]) {
                // case 4:
                if (x == a[i+1]) {
                    base += i - (N-i+1);
                }
                // case 1 rev:
                else if (x != a[i]) {
                    base += (i-1) * (N-i+1);
                }
            }
            else if (a[i] == a[i+1]) {
                // case 3:
                if (x == a[i-1]) {
                    base += (N-i+1) - i;
                }
                // case 2 rev:
                else if (x != a[i]) {
                    base += (i) * (N-i);
                }
            }
            else {
                // case 1:
                if (x == a[i-1]) {
                    base -= (i-1) * (N-i+1);
                }
                // case 2:
                else if (x == a[i+1]) {
                    base -= (i) * (N-i);
                }
            }
        }
        else {
            ll l = i-1;
            ll r = N-i;
            // case 5:
            if (a[i] != a[i-1] && x == a[i-1]) {
                base = base - (l*r*2) - l - r;
            }
            // case 5 rev:
            else if (a[i] == a[i-1] && x != a[i]) {
                base = base + (l*r*2) + l + r;
            }
        }
        a[i] = x;
        res[q] = base;
    }
    for (auto& r : res) {
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    vector<ll> a(N+2, 2e9);
    for (int i=1; i<=N; ++i) {
        cin >> a[i];
    }
    vector<pair<int,int>> queries(M);
    for (auto& q : queries) {
        cin >> q.first >> q.second;
    }
    solution(a, queries);
    return 0;
}