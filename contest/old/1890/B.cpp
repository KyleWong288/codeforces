#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M;

// if t has doubles, t is useless
// only care about left and right endpt of t, they need to be opposite of the double you split
int solution(string& s, string& t) {
    int pair1s = 0;
    int pair0s = 0;
    for (int i=0; i<N-1; ++i) {
        if (s[i] == s[i+1]) {
            if (s[i] == '1') {
                pair1s++;
            }
            else {
                pair0s++;
            }
        }
    }
    // 2 types
    if (pair1s && pair0s) {
        return 0;
    }
    // 0 types 
    if (!pair1s && !pair0s) {
        return 1;
    }
    // 1 type
    for (int i=0; i<M-1; ++i) {
        if (t[i] == t[i+1]) {
            return 0;
        }
    }
    if (pair1s && t[0] == '0' && t.back() == '0') {
        return 1;
    }
    if (pair0s && t[0] == '1' && t.back() == '1') {
        return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s, t;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M >> s >> t;
        res[i] = solution(s, t);
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