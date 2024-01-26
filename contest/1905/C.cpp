#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// original largest ssq can be constructed with monostack algo
// [t1,tm] is largest ssq, we shift to [tm, t1, tm-1], now [t1, tm-1] is the largest ssq
// this is bcos we know no one in between the original t's is greater due to the monostack algo
// at the end, the largest ssq will just be the last character(s), so no more shifts can be done, so check the final string
// do operations until all indices in stack have the same value
int solution(string& s) {
    int save = 0;
    vector<int> stack;
    for (int i=0; i<N; ++i) {
        while (stack.size() && s[stack.back()] < s[i]) {
            stack.pop_back();
        }
        stack.push_back(i);
    }
    // get saves:
    for (int i=1; i<stack.size(); ++i) {
        int i1 = stack[0];
        int i2 = stack[i];
        if (s[i1] == s[i2]) {
            ++save;
        }
    }
    // swap and verify:
    for (int i=0; i<stack.size()/2; ++i) {
        int i1 = stack[i];
        int i2 = stack[stack.size() - 1 - i];
        swap(s[i1], s[i2]);
    }
    for (int i=1; i<N; ++i) {
        if (s[i] < s[i-1]) {
            return -1;
        }
    }
    int res = max(0, (int)stack.size() - save - 1);
    return res;
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