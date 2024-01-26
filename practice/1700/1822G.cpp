#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
#include <unordered_map>
using namespace std;
typedef long long ll;

int N;
vector<int> squares;

// convert to freq map, special case when b = 1
// x * b = y, y * b = z, so b^2 = z / x -> we only have sqrt(1e6) possible values of b, just brute force all of them
ll solution(vector<ll>& v) {
    ll res = 0;
    unordered_map<ll,ll> freq;
    for (auto& x : v) {
        ++freq[x];
    }
    // treat each value as a_j
    for (auto& pr : freq) {
        ll aj = pr.first;
        ll f = pr.second;
        for (int sq=1; sq<=1000; ++sq) {
            if (sq == 1) {
                res += (f) * (f-1) * (f-2);
            }
            else if (aj % sq == 0) {
                ll ai = aj / sq;
                ll ak = aj * sq;
                if (freq.find(ai) != freq.end() && freq.find(ak) != freq.end()) {
                    res += (freq[ai] * freq[aj] * freq[ak]);
                }
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<ll> v(N);
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