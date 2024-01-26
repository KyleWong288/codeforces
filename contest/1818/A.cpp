#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;
typedef long long ll;

int N, K;

// if you have a disagreement, somebody leaves, so you should've just not included the leavers
// thus, just get frequency of same stances
int solution(vector<string>& stances) {
    unordered_map<string,int> freq;
    for (auto& x : stances) {
        freq[x]++;
    }
    return freq[stances[0]];
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> K;
        vector<string> stances(N);
        for (auto& x : stances) {
            cin >> x;
        }
        res[i] = solution(stances);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}