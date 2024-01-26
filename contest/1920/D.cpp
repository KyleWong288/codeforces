#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, Q;

int solution(vector<vector<ll>>& ops, vector<ll>& queries) {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        cin >> N >> Q;
        vector<vector<ll>> ops(N, vector<ll>(2));
        for (auto& pr : ops) {
            cin >> pr[0] >> pr[1];
        }
        vector<ll> queries(Q);
        for (auto& x : queries) {
            cin >> x;
        }
        solution(ops, queries);
    }
    return 0;
}