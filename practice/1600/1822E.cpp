#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int N;

// fails if odd or frequency of char is greater than N/2
// find all index pairs that match, you can fix 2 pairs in one operation if the characters differ
int solution(string& s) {
    if (N % 2) {
        return -1;
    }
    vector<int> freq(26, 0);
    for (auto& c : s) {
        freq[c-'a']++;
        if (freq[c-'a'] > N/2) {
            return -1;
        }
    }
    vector<int> swaps(26, 0);
    for (int i=0; i<N/2; ++i) {
        if (s[i] == s[N-i-1]) {
            swaps[s[i]-'a']++;
        }
    }
    // max heap stores # of needed swaps remaining for a char
    priority_queue<int> heap;
    for (auto& x : swaps) {
        if (x) {
            heap.push(x);
        }
    }
    int res = 0;
    while (heap.size() > 1) {
        int f1 = heap.top()-1;
        heap.pop();
        int f2 = heap.top()-1;
        heap.pop();
        if (f2 > 0) {
            heap.push(f2);
        }
        if (f1 > 0) {
            heap.push(f1);
        }
        ++res;
    }
    if (heap.size()) {
        res += heap.top();
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    string s;
    vector<int> res(T);
    for (int i=0; i<T; ++i) {
        cin >> N >> s;
        res[i] = solution(s);
    }
    for (auto& r : res) {
        cout << r << endl;
    }
    return 0;
}