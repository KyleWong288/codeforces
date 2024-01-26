#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_set>
using namespace std;
typedef long long ll;

int N;

// one inversion means full sort except one pair of adjacent elements are swapped
// answer will be f-1 (one purposeful perturb) or f+1 (sort then perturb), where f is # of ops to full sort
// if we have cycle with two adjacent values, we can get f-1
int solution(vector<int>& p) {
    int res = 0;
    bool adjCyc = 0;
    for (int i=1; i<=N; ++i) {
        unordered_set<int> cycle;
        cycle.insert(i);
        while (p[i] != i) {
            cycle.insert(p[i]);
            if (cycle.find(p[i]-1) != cycle.end() || cycle.find(p[i]+1) != cycle.end()) {
                adjCyc = 1;
            }
            int temp = p[p[i]];
            p[p[i]] = p[i];
            p[i] = temp;
            ++res;
        }
    }
    if (adjCyc) {
        return res-1;
    }
    else {
        return res+1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> p(N+1);
        for (int j=1; j<=N; ++j) {
            cin >> p[j];
        }
        res[i] = solution(p);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}