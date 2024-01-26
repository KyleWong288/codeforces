#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

ll n, k, x;
ll CAP = 2e18;

// to construct lex smallest, spam b in * from right to left -> almost like making a base k number
// need to treat consecutive * differently, if we have c consecutive *, treat it like [0, c*k]
// counting: count at previous * is p, range at current * is [p+1, c*k*p + p]
// store a vector of ranges, then go backwards to know how many b to spam at each chunk of *
void solution(string& str) {
    // edge case for k = 0:
    if (k == 0) {
        for (auto& ch : str) {
            if (ch == 'a') {
                cout << 'a';
            }
        }
        cout << endl;
        return;
    }
    // compress multiple *s:
    vector<ll> coeff;
    string s = "";
    for (int i=0; i<n; ++i) {
        if (str[i] == '*') {
            if (s.empty() || s.back() == 'a') {
                s.push_back('*');
                coeff.push_back(1);
            }
            else {
                coeff.back() += 1;
            }
        }
        else {
            s.push_back('a');
            coeff.push_back(0);
        }
    }
    n = s.size();
    // get counts:
    vector<ll> sizes;
    sizes.push_back(1);
    for (int i=n-1; i>=0; --i) {
        if (!coeff[i]) { continue; }
        ll p = sizes.back();
        // if overflow, set remaining sizes to inf:
        if (CAP / (k * coeff[i]) <= p) { 
            while (i >= 0) {
                sizes.push_back(CAP);
                --i;
            }
            break;
        }
        ll next = coeff[i] * p * k + p;
        sizes.push_back(next);
    }
    ll cur = x;
    vector<ll> spams(sizes.size());
    for (int i=sizes.size()-1; i>=0; --i) {
        ll use = cur / sizes[i];
        spams[i] = use;
        cur -= (sizes[i] * use);
    }
    // build:
    int sp = spams.size()-2;
    for (int i=0; i<n; ++i) {
        if (!coeff[i]) {
            cout << 'a';
        }
        else {
            for (int j=0; j<spams[sp]; ++j) {
                cout << 'b';
            }
            --sp;
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    while (T--) {
        cin >> n >> k >> x >> s;
        --x;
        solution(s);
    }
    return 0;
}