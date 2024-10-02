#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int doFrontGuess(string& s, char c) {
    int res;
    cout << "? " << c << s << endl;
    cout.flush();
    cin >> res;
    return res;
}

int doBackGuess(string& s, char c) {
    int res;
    cout << "? " << s << c << endl;
    cout.flush();
    cin >> res;
    return res;
}

// slide left, slide right
void solve(int n) {
    string build;
    // initial guess:
    int resp = doFrontGuess(build, '0');
    if (resp > 0) build = "0";
    else {
        string edge(n, '1');
        cout << "! " << edge << endl;
        cout.flush();
        return;
    }
    if (n == 1) {
        cout << "! 0" << endl;
        cout.flush();
        return;
    }
    // left guesses:
    int add0 = doFrontGuess(build, '0');
    int add1 = doFrontGuess(build, '1');
    while (add0 > 0 || add1 > 0) {
        if (add0 > 0) build = '0' + build;
        else build = '1' + build;
        if (build.size() == n) {
            cout << "! " << build << endl;
            cout.flush();
            return;
        }
        add0 = doFrontGuess(build, '0');
        add1 = doFrontGuess(build, '1');
    }
    // right guesses:
    while (build.size() < n-1) {
        add0 = doBackGuess(build, '0');
        if (add0 > 0) build += '0';
        else build += '1';
    }
    if (build.size() == n-1) {
        resp = doBackGuess(build, '0');
        if (resp > 0) build += '0';
        else build += '1';
    }
    cout << "! " << build << endl;
    cout.flush();
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        solve(N);
    }
    return 0;
}