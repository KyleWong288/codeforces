#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// we need same relative ordering of numbers, smaller can be replaced but larger ones cause instant fail
int solution(vector<int>& a, vector<int>& b) {
    

}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N;
        vector<int> a(N);
        vector<int> b(N);
        for (auto& x : a) {
            cin >> x;
        }
        for (auto& x : b) {
            cin >> x;
        }
        res[i] = solution(a, b);
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