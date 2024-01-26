#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

int N;

// as soon as we hit a 0, we can make the prefix sum anything
// brute force each index i, get how many endpts starting on i+1 have a subarray sum of 0
// # of endpts = max(# of 0s, freq of suffix sum)
// each index looks like (prefix sum [0:i]) ([i+1 : set of endpts])
int solution(vector<ll>& a) {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
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