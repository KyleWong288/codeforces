#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, Q;

// make a linked list and slide the last node to proper position
void solution(vector<int>& queries) {
    vector<vector<int>> res(Q, vector<int>(3, -1));
    int hasEnd = N-1;
    for (int i=0; i<Q; ++i) {
        if (hasEnd == queries[i]) {
            continue;
        }
        res[i][0] = N;
        res[i][1] = hasEnd;
        res[i][2] = queries[i];
        hasEnd = queries[i];
    }
    for (int i=1; i<N; ++i) {
        cout << i << " " << i+1 << endl;
    }
    for (auto& move : res) {
        cout << move[0] << " " << move[1] << " " << move[2] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        vector<int> q(Q);
        for (auto& x : q) {
            cin >> x;
        }
        solution(q);
    }
    return 0;
}