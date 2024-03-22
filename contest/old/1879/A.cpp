#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N;

// highest weight we can choose is the first, make sure no one has more endurance
int solution(vector<pair<int,int>>& v) {
    int w = v[0].first;
    int e = v[0].second;
    for (int i=1; i<N; ++i) {
        if (v[i].first >= w && v[i].second >= e) {
            return -1;
        }
    }
    return w;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<pair<int,int>> v(N);
        for (auto& x : v) {
            cin >> x.first >> x.second;
        }
        res[i] = solution(v);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}