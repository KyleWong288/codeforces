#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

int N;

// loop through each point: check same x, same y
// right diagonal: check same difference between (y - x), both shift by 1
// left diagonal: check same sum between (y + x), shift by +1 and -1
ll solution(vector<pair<int,int>>& pts) {
    ll res = 0;
    // preprocess:
    map<int,int> freqX;
    map<int,int> freqY;
    map<int,int> freqDiagR;
    map<int,int> freqDiagL;
    for (auto& pt : pts) {
        ++freqX[pt.first];
        ++freqY[pt.second];
        ++freqDiagR[pt.second - pt.first];
        ++freqDiagL[pt.second + pt.first];
    }
    // count:
    for (auto& pt : pts) {
        res += freqX[pt.first];
        res += freqY[pt.second];
        res += freqDiagR[pt.second - pt.first];
        res += freqDiagL[pt.second + pt.first];
        res -= 4;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    vector<ll> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<pair<int,int>> pts(N);
        for (auto& pt : pts) {
            cin >> pt.first >> pt.second;
        }
        res[i] = solution(pts);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}