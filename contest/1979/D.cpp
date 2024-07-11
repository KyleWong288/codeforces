#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, K;

// checks if string is k-proper
bool works(string& s) {
    for (int i=0; i<K; ++i) {
        if (s[i] != s[0]) return 0;
    }
    for (int i=0; i<N-K; ++i) {
        if (s[i] == s[i+K]) return 0;
    }
    return 1;
}

// first time encountering a failing segment, split it. then check the new one
// if no failing segment, already k-proper, so just reverse the entire string
int solve(string& s) {
    if (works(s)) return N;
    for (int i=0; i<N; ++i) {
        int j = i;
        while (j < N && s[i] == s[j]) ++j;
        int len = j - i;
        if (len != K) {
            // create the new string and validate
            int use = len % K;
            if (use == 0) use = K;
            string t;
            for (int p=i+use; p<N; ++p) {
                t += s[p];
            }
            for (int p=i+use-1; p>=0; --p) {
                t += s[p];
            }
            if (works(t)) {
                return i + use;
            }
            else {
                return -1;
            }
        }
        i = j-1;
    }
    return -69;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        string s;
        cin >> N >> K >> s;
        res[i] = solve(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}