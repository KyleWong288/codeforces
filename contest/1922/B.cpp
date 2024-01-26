#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

int N;

// loop through each stick, treat like its the hypotenuse: how many pairs sum to less than me?
// if hypotenuse is h, we need at least another h since 2^(h-1) + 2^(h-1) isn't long enough
// then, if we have another h, pairing with any other side works
ll solution(vector<ll>& a) {
    ll res = 0;
    map<ll,ll> freq;
    for (auto& x : a) {
        freq[x]++;
    }
    ll prev = 0;
    for (auto& pr : freq) {
        ll f = pr.second;
        ll pairs = (f) * (f-1) / 2;
        ll trips = (f) * (f-1) * (f-2) / 6;
        res += pairs * prev + trips;
        prev += f;
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
        vector<ll> a(N);
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