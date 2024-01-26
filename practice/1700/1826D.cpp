#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N;

// to minimize (r-l), we want higher l and lower r
// left sweep (i from 0 to n forwards): score = i + nums[i], higher i means higher l
// right sweep (i from 0 to n backwards): score = i + nums[i], higher i means lower r
// maximize score over all m by using left best and right best
int solution(vector<int>& v) {
    // stores <val, index>
    vector<pair<int,int>> sweepL(N);
    int best = 0;
    for (int i=0; i<N; ++i) {
        if (v[i] + i > best) {
            sweepL[i] = {v[i], i};
            best = v[i] + i;
        }
        else {
            sweepL[i] = sweepL[i-1];
        }
    }
    vector<pair<int,int>> sweepR(N);
    best = 0;
    for (int i=N-1; i>=0; --i) {
        int revI = N - i - 1;
        if (v[i] + revI > best) {
            sweepR[i] = {v[i], i};
            best = v[i] + revI;
        }
        else {
            sweepR[i] = sweepR[i+1];
        }
    }
    int res = 0;
    for (int i=1; i<N-1; ++i) {
        int sum = v[i] + sweepL[i-1].first + sweepR[i+1].first - (sweepR[i+1].second - sweepL[i-1].second);
        res = max(res, sum);
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> v(N);
        for (auto& x : v) {
            cin >> x;
        }
        res[i] = solution(v);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}