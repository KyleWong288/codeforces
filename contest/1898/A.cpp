#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, K;

// 0 op: already has k B
// 1 op: too many B -> replace prefix with A, too few B -> replace prefix with B
void solution(string& s) {
    int cntA = 0;
    int cntB = 0;
    for (auto& ch : s) {
        if (ch == 'A') {
            ++cntA;
        }
        else {
            ++cntB;
        }
    }
    if (cntB == K) {
        cout << 0 << endl;
        return;
    }
    else {
        int i = -1;
        cout << 1 << endl;
        if (cntB > K) {
            int need = cntB - K;
            while (need) {
                ++i;
                if (s[i] == 'B') {
                    --need;
                }
            }
            cout << i+1 << " A" << endl;
        }
        else {
            int need = -1 * (cntB - K);
            while (need) {
                ++i;
                if (s[i] == 'A') {
                    --need;
                }
            }
            cout << i+1 << " B"<< endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    while (T--) {
        cin >> N >> K >> s;
        solution(s);
    }
    return 0;
}