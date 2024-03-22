#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

// just choose odd numbers
void solution(int N) {
    vector<int> res(N);
    for (int i=0; i<N; ++i) {
        res[i] = 2*i + 1;
    }
    for (auto& x : res) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        solution(N);
    }
    return 0;
}