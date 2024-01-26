#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int H, W;

// odd dist: alice win or draw, bob tries to move as far away as possible
// even dist: bob win or draw, alice tries to move as far away as possible
int solution(int aRow, int aCol, int bRow, int bCol) {
    if (aRow >= bRow) {
        return 0;
    }
    int diff = abs(aRow - bRow);
    // alice win, bob tries to go far
    if (diff % 2) {
        int moves = diff / 2;
        int farLB = max(1, bCol - moves);
        int farRB = min(W, bCol + moves);
        int farLA = max(1, aCol - moves - 1);
        int farRA = min(W, aCol + moves + 1);
        if (farLA <= farLB && farRB <= farRA) {
            return 1;
        }
        return 0;
    }
    // bob win, alice tries to go far
    else {
        int moves = diff / 2;
        int farLB = max(1, bCol - moves);
        int farRB = min(W, bCol + moves);
        int farLA = max(1, aCol - moves);
        int farRA = min(W, aCol + moves);
        if (farLB <= farLA && farRA <= farRB) {
            return 2;
        }
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    int xa, ya, xb, yb;
    for (int i=0; i<T; ++i) {
        cin >> H >> W >> xa >> ya >> xb >> yb;
        res[i] = solution(xa, ya, xb, yb);
    }
    for (auto& r : res) {
        if (r == 0) {
            cout << "Draw" << endl;
        }
        else if (r == 1) {
            cout << "Alice" << endl;
        }
        else {
            cout << "Bob" << endl;
        }
    }
    return 0;
}