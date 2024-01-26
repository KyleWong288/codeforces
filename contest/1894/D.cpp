#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

int N, M;

// placing B in reverse sorted order will preserve the original length of LIS(A)
// place B[i] after the smallest larger number in A
// B[i] won't cause an inbetween addition, and B[i] is lower than its predecessor in C, so LIS(A) guaranteed to be same
void solution(vector<int>& a, vector<int>& b) {
    vector<int> pref;
    vector<vector<int>> bPlaces(N);
    sort(b.rbegin(), b.rend());
    // stores <val, last occurrence of val>
    map<int,int> lastMap;
    for (int i=0; i<N; ++i) {
        lastMap[a[i]] = i;
    }
    for (auto& x : b) {
        auto pred = lastMap.lower_bound(x);
        if (pred == lastMap.end()) { // no number in a is smaller, place in prefix of C
            pref.push_back(x);
        }
        else {
            int idx = pred->second;
            bPlaces[idx].push_back(x);
        }
        
    }
    for (auto& x : pref) {
        cout << x << " ";
    }
    for (int i=0; i<N; ++i) {
        cout << a[i] << " ";
        for (auto& x : bPlaces[i]) {
            cout << x << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        cin >> N >> M;
        vector<int> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        vector<int> b(M);
        for (auto& x : b) {
            cin >> x;
        }
        solution(a, b);
    }
    return 0;
}