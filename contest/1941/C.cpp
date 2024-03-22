#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// for map, remove 'a'
// for pie, remove 'i'
// for mapie, remove 'p'
int solve(string& s) {
    int res = 0;
    for (int i=0; i<N-2; ++i) {
        string t = "";
        string q = s.substr(i,3);
        if (i <= N-5) {
            t = s.substr(i,5);
        }
        if (t == "mapie") {
            ++res;
            i += 4;
        }
        else if (q == "map") {
            ++res;
            i += 2;
        }
        else if (q == "pie") {
            ++res;
            i += 2;
        }
    }
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
        res[i] = solve(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}