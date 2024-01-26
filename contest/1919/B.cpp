#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;

int N;

// always best to take m = 1
int solution(string& s) {
    int cnt = 0;
    for (auto& ch : s) {
        if (ch == '+') {
            ++cnt;
        }
        else {
            --cnt;
        }
    }
    return abs(cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> s;
        res[i] = solution(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}