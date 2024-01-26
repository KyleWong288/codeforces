#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// use stack to simulate +/-
// 3 states: 0 = unknown, 1 = sorted, -1 = known unsorted up to this point
// read 1: mark everything in stack as 1
// read 0: mark stack.back as -1 (if we pop this, the rest is unknown aka 0, which we already have)
// check contradictions: while we have at least one -1 in the stack, it is unsorted
int solution(string& s) {
    int n = s.size();
    vector<int> stack;
    for (auto& ch : s) {
        if (ch == '+') {
            if (stack.empty()) {
                stack.push_back(1);
            }
            else if (stack.back() == -1) {
                stack.push_back(-1);
            }
            else {
                stack.push_back(0);
            }
        }
        else if (ch == '-') {
            stack.pop_back();
        }
        else if (ch == '1') {
            if (!stack.empty() && stack.back() == -1) {
                return 0;
            }
            else {
                for (int i=stack.size()-1; i>=0; --i) {
                    if (stack[i] == 1) { break; }
                    stack[i] = 1;
                }
            }
        }
        else {
            if (stack.empty() || stack.back() == 1) {
                return 0;
            }
            else {
                stack.back() = -1;
            }
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> s;
        res[i] = solution(s);
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