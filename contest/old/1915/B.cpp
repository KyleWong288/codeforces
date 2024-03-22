#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string l1, l2, l3;
    vector<char> res(T);
    for (int i=0; i<T; ++i) {
        cin >> l1 >> l2 >> l3;
        vector<int> freq(3, 0);
        for (auto& ch : l1) {
            if (ch != '?') {
                freq[ch-'A']++;
            }
        }
        for (auto& ch : l2) {
            if (ch != '?') {
                freq[ch-'A']++;
            }
        }
        for (auto& ch : l3) {
            if (ch != '?') {
                freq[ch-'A']++;
            }
        }
        for (int j=0; j<3; ++j) {
            if (freq[j] == 2) {
                res[i] = 'A' + j;
            }
        }
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}