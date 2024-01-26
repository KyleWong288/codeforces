#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;
typedef long long ll;

int N;

// all have to be same number, or two numbers with equal freq
int solution(vector<int>& b) {
    unordered_map<int,int> freq;
    for (auto& x : b) {
        freq[x]++;
    }
    if (freq.size() > 2) {
        return 0;
    }
    if (freq.size() == 1) {
        return 1;
    }
    vector<int> f;
    for (auto& pr : freq) {
        f.push_back(pr.second);
    }
    if (N % 2) {
        if (f[0] == f[1] + 1 || f[0] + 1 == f[1]) {
            return 1;
        }
        return 0;
    }
    else {
        if (f[0] == f[1]) {
            return 1;
        }
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> b(N);
        for (auto& x : b) {
            cin >> x;
        }
        res[i] = solution(b);
    }
    for (auto& r : res) {
        if (r) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}