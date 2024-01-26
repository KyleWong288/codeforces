#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_set>
using namespace std;
typedef long long ll;

// add chars in s in sorted order and build t using two ptrs on left and right endpts
// case 1: have >= 2 of char x: place on both ends
// idea: we want to minimize both t[i] and t[n-i-1]
// case 2: have one of char x and >= 2 char types remaining: place x behind the remaining substring of s
// idea: the remaining substring without x (ss) is sorted, and x is uniquely small so putting it behind ss means the reverse(ss+x) < ss+x
// case 3: have one of char x and 1 char type remaining: place x in the middle
// idea: we try above but theres no effective change from x+ss to ss+x, best place to put x is in the middle since closer to one side == farther from other side
void solution(string& s) {
    int N = s.size();
    sort(s.begin(), s.end());
    vector<char> t(N);
    int l = 0;
    int r = N-1;
    for (int i=0; i<N; i+=2) {
        // case 1
        if (i == N-1 || s[i] == s[i+1]) {
            t[l] = s[i];
            t[r] = s[i];
        }
        else {
            unordered_set<char> types;
            for (int j=i+1; j<N; ++j) {
                types.insert(s[j]);
            }
            // case 2
            if (types.size() >= 2) {
                for (int j=i+1; j<N; ++j) {
                    t[l++] = s[j];
                }
                t[l] = s[i];
            }
            // case 3
            else {
                for (int j=i; j<N; ++j) {
                    t[l++] = s[i+1];
                }
                t[N/2] = s[i];
            }
            break;
        }
        ++l;
        --r;
    }
    for (auto& ch : t) {
        cout << ch;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    while(T--) {
        cin >> s;
        solution(s);
    }
    return 0;
}