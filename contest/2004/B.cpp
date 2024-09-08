#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// lock all the doors in the parts where the intervals overlap
// say intersection is [l, r], so we lock doors (l-1,l), ... (r,r+1), which is r - l + 2 doors
// then we can maybe release the leftmost & rightmost door, if its at the edge of both players range
int solve(int al, int ar, int bl, int br) {
    int l = max(al, bl);
    int r = min(ar, br);
    if (l > r) {
        return 1;
    }
    else {
        int res = r - l + 2;
        if (r == ar && r == br) --res;
        if (l == al && l == bl) --res;
        return res;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    int al, ar, bl, br;
    for (int i=0; i<T; ++i) {
        cin >> al >> ar >> bl >> br;
        res[i] = solve(al, ar, bl, br);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}