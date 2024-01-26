#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// make one and see if we can make another
// valid RBS using +1/-1 algo: you never go neg and end on diff of 0 -> frontloading open always works
// now see if we can swap ) at index r with ( at index l -> this means swapping -1 with +1, so the subarray [l:r-1] decreases by 2
// if the whole subarray of diffs is >= 2, this works
// only subarray you need to check is between last '(' and first ')', all swaps include this range
int solution(string& s) {
    int n = s.size();
    int need = n/2;
    int open = 0;
    int close = 0;
    for (auto& ch : s) {
        if (ch == '(') { ++open; }
        if (ch == ')') { ++close; } 
    }
    // create base solution:
    int lastOpen = -1;
    int firstClose = -1;
    string seq = s;
    for (int i=0; i<n; ++i) {
        if (seq[i] == '?') {
            if (open < need) {
                seq[i] = '(';
                ++open;
                if (open == need) { lastOpen = i; }
            }
            else {
                seq[i] = ')';
                ++close;
                if (firstClose == -1) { firstClose = i; }
            }
        }
    }
    if (lastOpen == -1 || firstClose == -1) { return 1; }
    // check if we can swap:
    int diff = 0;
    for (int i=0; i<lastOpen; ++i) {
        seq[i] == '(' ? ++diff : --diff;
    }
    for (int i=lastOpen; i<firstClose; ++i) {
        seq[i] == '(' ? ++diff : --diff;
        if (diff < 2) {
            return 1;
        }
    }
    return 0;
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