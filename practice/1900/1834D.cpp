#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

// try each student as the highest student -> take exactly their range (simple proof by contra)
// the lowest student is the interval with minimum intersection -> break this by cases
// no overlap case: low r < high l or high r < low l
// left overlap: sort by right end points and bs
// right overlap: sort by left end points and bs
// envelope: ?????
int solution() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        res[i] = solution();
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}