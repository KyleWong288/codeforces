#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// template that matches all: choose some upper case letter not used
// then, find one index that we can switch the letter to that index in c
int solution(string& a, string& b, string& c) {
    int found = 0;
    for (int i=0; i<N; ++i) {
        if (a[i] != c[i] && b[i] != c[i]) {
            found = 1;
        }
    }
    return found;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string a, b, c;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> a >> b >> c;
        res[i] = solution(a, b, c);
    }
    for (auto& r : res) {
        cout << (r ? "YES\n" : "NO\n");
    }
    return 0;
}