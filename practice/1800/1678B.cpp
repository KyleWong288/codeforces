#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// think of it as odd compression: [E,E,O,E,E,O,E,E], we move the left odd portion and the right odd portion together
// how to minimize # of subsegments?: we need to full kill a subsegment
// size = 1: always should be killed
// size >= 3: we can't full kill any subsegment of size 3 or greater (each subsegment generates at most 2 ops, so we would be stealing)
// size = 2: for some pair, we get [O,E,O], where E has size 2, so we can convert all 3 segments to the same value with even size
int solution(string& s) {
    int res = 0;
    int consec = 1;
    for (int i=1; i<N; ++i) {
        if (s[i] != s[i-1]) {
            if (consec % 2) {
                ++res;
                ++consec;
                s[i] == '1' ? s[i] = '0' : s[i] = '1';
            }
            else {
                consec = 1;
            }
        }
        else {
            ++consec;
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
        res[i] = solution(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}