#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N;

// start at middle value v, have left and right pointers move outwards seeking v-1 and v+1
// each pair we find means we don't need an operation for that pair
int solution(vector<int>& v) {
    int good = 0;
    if (v.size() % 2) { // odd case
        int target = v.size() / 2 + 1;
        int l = 0;
        int r = 0;
        for (int i=0; i<N; ++i) {
            if (v[i] == target) {
                l = i;
                r = i;
            }
        }
        int targetL = target - 1;
        int targetR = target + 1;
        while (l >= 0 && r < N) {
            while (l >= 0 && v[l] != targetL) {
                --l;
            }
            if (l < 0) { break; }
            while (r < N && v[r] != targetR) {
                ++r;
            }
            if (r >= N) { break; }
            ++good;
            --l;
            ++r;
            --targetL;
            ++targetR;
        }
    }
    else { // even case
        int target = v.size() / 2;
        int l = 0;
        int r = 0;
        for (int i=0; i<N; ++i) {
            if (v[i] == target) {
                l = i;
            }
            if (v[i] == target+1) {
                r = i;
            }
        }
        if (r < l) { // edge case, need to swap all
            return target;
        }
        ++good;
        int targetL = target - 1;
        int targetR = target + 2;
        while (l >= 0 && r < N) {
            while (l >= 0 && v[l] != targetL) {
                --l;
            }
            if (l < 0) { break; }
            while (r < N && v[r] != targetR) {
                ++r;
            }
            if (r >= N) { break; }
            ++good;
            --l;
            ++r;
            --targetL;
            ++targetR;
        }
    }
    int res = (v.size() / 2) - good;
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