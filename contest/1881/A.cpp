#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M;

// brute force
int solution(string& x, string& s) {
    for (int i=0; i<10; ++i) {
        int end = x.size() - s.size();
        for (int j=0; j<=end; ++j) {
            if (x.substr(j, s.size()) == s) {
                return i;
            }
        }
        x += x;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string x, s;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> M;
        cin >> x >> s;
        res[i] = solution(x, s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}