#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// target is smallest
int solution(int a, int b, int c) {
    vector<int> v = {a,b,c};
    sort(v.begin(), v.end());
    int target = v[0];
    int cnt = 0;
    if (v[1] % target) {
        return 0;
    }
    else {
        cnt += v[1] / target - 1;
    }
    if (v[2] % target) {
        return 0;
    }
    else {
        cnt += v[2] / target - 1;
    }
    int res = (cnt <= 3);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, a, b, c;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> a >> b >> c;
        res[i] = solution(a, b, c);
    }
    for (auto& r : res) {
        if (r) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}