#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// greedily match x largest in A with x smallest in B for the special indices
// remaining match small in A with small in B
void solution(vector<int>& a, vector<int>& b, int n, int x) {
    vector<pair<int,int>> arr(n);
    for (int i=0; i<n; ++i) {
        arr[i] = {a[i], i};
    }
    sort(arr.begin(), arr.end());
    sort(b.begin(), b.end());
    vector<int> res(n);
    for (int i=0; i<x; ++i) {
        int idx = arr[n-1-i].second;
        res[idx] = b[x-1-i];
    }
    for (int i=0; i<n-x; ++i) {
        int idx = arr[i].second;
        res[idx] = b[i+x];
    }
    int cnt = 0;
    for (int i=0; i<n; ++i) {
        if (a[i] > res[i]) {
            ++cnt;
        }
    }
    if (cnt != x) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for (auto& r : res) {
            cout << r << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, N, X;
    cin >> T;
    while (T--) {
        cin >> N >> X;
        vector<int> a(N);
        vector<int> b(N);
        for (auto& x : a) {
            cin >> x;
        }
        for (auto& x : b) {
            cin >> x;
        }
        solution(a, b, N, X);
    }
    return 0;
}