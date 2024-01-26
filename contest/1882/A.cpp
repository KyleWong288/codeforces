#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int N;

int solution(vector<int>& v) {
    int res = 0;
    for (int i=0; i<N; ++i) {
        ++res;
        if (res == v[i]) {
            ++res;
        }
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