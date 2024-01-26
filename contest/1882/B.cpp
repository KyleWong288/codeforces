#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;

int N;

// all elements are between 1 and 50, brute force try each element to remove and see resulting union
int solution(vector<set<int>>& sets) {
    set<int> all;
    for (auto& set : sets) {
        for (auto& x : set) {
            all.insert(x);
        }
    }
    int res = 0;
    for (auto& v : all) {
        set<int> build;
        for (auto& set : sets) {
            if (set.find(v) == set.end()) {
                for (auto& x : set) {
                    build.insert(x);
                }
            }
        }
        res = max(res, (int)build.size());
    }
    return res;
}

int main() {
    int T, k, x;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<set<int>> sets(N);
        for (int j=0; j<N; ++j) {
            cin >> k;
            set<int> set;
            while (k--) {
                cin >> x;
                set.insert(x);
            }
            sets[j] = set;
        }
        res[i] = solution(sets);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}