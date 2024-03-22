#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N;

// find all the forced 0 bits
// after computing all forces, see if its possible
void solution(vector<vector<int>>& m) {
    if (N == 1) {
        cout << "YES" << endl;
        cout << 69 << endl;
        return;
    }
    // use[i] = list of all usable bits for res[i]
    vector<vector<bool>> use(N, vector<bool>(31, 1));
    // compute forced 0s:
    for (int i=0; i<N; ++i) {
        for (int j=i+1; j<N; ++j) {
            for (int b=0; b<31; ++b) {
                if (((m[i][j] >> b) & 1) == 0) {
                    use[i][b] = 0;
                    use[j][b] = 0;
                }
            }
        }
    }
    // check if possible:
    for (int i=0; i<N; ++i) {
        for (int j=i+1; j<N; ++j) {
            for (int b=0; b<31; ++b) {
                if (((m[i][j] >> b) & 1) == 1) {
                    if (use[i][b] == 0 && use[j][b] == 0) {
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
        }
    }
    // build res:
    vector<int> res(N, 0);
    for (int i=0; i<N; ++i) {
        for (int b=0; b<31; ++b) {
            if (use[i][b]) {
                res[i] += (1 << b);
            }
        }
    }
    cout << "YES" << endl;
    for (auto& r : res) {
        cout << r << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<vector<int>> m(N, vector<int>(N));
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                cin >> m[i][j];
            }
        }
        solution(m);
    }
    return 0;
}