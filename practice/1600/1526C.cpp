#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

int N;

// track running pos amount and take all takeable negs
// since we blindly take all negs, we can use a heap to decide and replace bad decisions
int solution(vector<ll>& v) {
    int res = 0;
    ll pos = 0;
    ll neg = 0;
    priority_queue<ll> pq; // max heap, stores abs value of negs
    for (auto& x : v) {
        if (x >= 0) {
            pos += x;
            ++res;
        }
        else {
            ll n = -1 * x;
            // can't drink n:
            if (n > pos) { 
                continue;
            }
            // drink n without replacement:
            if (n + neg <= pos) {
                neg += n;
                pq.push(n);
            }
            // drink n with replacement:
            else {
                if (n < pq.top()) {
                    neg = neg - pq.top() + n;
                    pq.pop();
                    pq.push(n);
                }
            }
        }
    }
    res += pq.size();
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    vector<ll> v(N);
    for (auto& x : v) {
        cin >> x;
    }
    cout << solution(v) << endl;
    return 0;
}