#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;
typedef long long ll;

int N;

// need at least 2 pairs of dupes to work
void solution(vector<int>& a) {
    vector<int> res(N, 1);
    unordered_map<int,int> freq;
    for (auto& x : a) {
        freq[x]++;
    }
    vector<int> dupeVals;
    int numDupes = 0;
    for (auto& pr : freq) {
        if (pr.second >= 2) {
            dupeVals.push_back(pr.first);
        }
    }
    if (dupeVals.size() < 2) {
        cout << -1 << endl;
        return;
    }
    // insert a 2 for one pair of dupe
    for (int i=0; i<N; ++i) {
        if (a[i] == dupeVals[0]) {
            res[i] = 2;
            break;
        }
    }
    // insert a 3 for another pair of dupe
    for (int i=0; i<N; ++i) {
        if (a[i] == dupeVals[1]) {
            res[i] = 3;
            break;
        }
    }
    for (auto& x : res) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> a(N);
        for (auto& x : a) {
            cin >> x;
        }
        solution(a);
    }
    return 0;
}