#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

int N;
char trump;

// partition by suit, ignore trump suit
// if non-trump suit batch has odd len, i need to use a trump suit card
// then finish off trump suit
void solve(vector<string>& cards) {
    // partition:
    map<char, vector<string>> parts;
    for (auto& card : cards) {
        char suit = card[1];
        parts[suit].push_back(card);
    }
    for (auto& pr : parts) {
        sort(pr.second.begin(), pr.second.end());
    }
    // get extra:
    if (trump != 'C' && parts['C'].size() % 2) {
        if (parts[trump].empty()) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        parts['C'].push_back(parts[trump].back());
        parts[trump].pop_back();
    }
    if (trump != 'D' && parts['D'].size() % 2) {
        if (parts[trump].empty()) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        parts['D'].push_back(parts[trump].back());
        parts[trump].pop_back();
    }
    if (trump != 'H' && parts['H'].size() % 2) {
        if (parts[trump].empty()) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        parts['H'].push_back(parts[trump].back());
        parts[trump].pop_back();
    }
    if (trump != 'S' && parts['S'].size() % 2) {
        if (parts[trump].empty()) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        parts['S'].push_back(parts[trump].back());
        parts[trump].pop_back();
    }
    // guaranteed to work if i reach here:
    vector<int> suits = {'C','D','H','S'};
    for (int i=0; i<4; ++i) {
        char suit = suits[i];
        for (int i=0; i<parts[suit].size(); i+=2) {
            cout << parts[suit][i] << " " << parts[suit][i+1] << endl;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> trump;
        vector<string> cards(2*N);
        for (auto& c : cards) {
            cin >> c;
        }
        solve(cards);
    }
    return 0;
}