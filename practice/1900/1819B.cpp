#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;

int N;

// find the rectangle(s) with largest height H or largest width W; either H or W is original length
// also know total area A, so the rectangle is either (H, A/H) or (A/W, W)
// put cuts into batches of horz (produce same width) or batches of vert (produce same height)
// we know area and side length -> create subrect -> recompute new area and side length for subrect
// try (H, A/H): vert cuts, horz cuts ...
// try (A/W, W): horz cuts, vert cuts ...
void solve(vector<vector<ll>>& rects) {
    int goodH = 1, goodW = 1;
    ll maxH = 0, maxW = 0, area = 0;
    for (auto& r : rects) {
        area += (r[0] * r[1]);
        maxH = max(maxH, r[0]);
        maxW = max(maxW, r[1]);
    }
    // try (A/W, W):
    // maps <height/width to rect id>
    map<int, vector<int>> mapH;
    map<int, vector<int>> mapW;
    for (int i=0; i<N; ++i) {
        mapH[rects[i][0]].push_back(i);
        mapW[rects[i][1]].push_back(i);
    }
    vector<bool> vis(N, 0);
    ll curH = area / maxW;
    ll curW = maxW;
    if (area % maxW) {
        goodW = 0;
    }
    bool getW = 1;
    while (curH && curW) {
        if (getW) {
            ll delH = 0;
            for (auto& id : mapW[curW]) {
                if (!vis[id]) {
                    delH += rects[id][0];
                    vis[id] = 1;
                }
            }
            if (delH == 0) {
                goodW = 0;
                break;
            }
            curH -= delH;
        }
        else {
            ll delW = 0;
            for (auto& id : mapH[curH]) {
                if (!vis[id]) {
                    delW += rects[id][1];
                    vis[id] = 1;
                }
            }
            if (delW == 0) {
                goodW = 0;
                break;
            }
            curW -= delW;
        }
        getW = !getW;
    }
    // try (H, A/H):
    curH = maxH;
    curW = area / maxH;
    vis.clear();
    vis.resize(N, 0);
    if (area % maxH) {
        goodH = 0;
    }
    bool getH = 1;
    while (curH && curW) {
        if (getH) {
            ll delW = 0;
            for (auto& id : mapH[curH]) {
                if (!vis[id]) {
                    delW += rects[id][1];
                    vis[id] = 1;
                }
            }
            if (delW == 0) {
                goodH = 0;
                break;
            }
            curW -= delW;
        }
        else {
            ll delH = 0;
            for (auto& id : mapW[curW]) {
                if (!vis[id]) {
                    delH += rects[id][0];
                    vis[id] = 1;
                }
            }
            if (delH == 0) {
                goodH = 0;
                break;
            }
            curH -= delH;
        }
    }
    // avoid double counting a square:
    if (goodH && goodW && (maxH == maxW && maxH == (area / maxW))) {
        goodW = 0;
    }
    cout << goodH + goodW << endl;
    if (goodH) {
        cout << maxH << " " << (area / maxH) << endl;
    }
    if (goodW) {
        cout << (area / maxW) << " " << maxW << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<vector<ll>> rects(N, vector<ll>(2));
        for (auto& r : rects) {
            cin >> r[0] >> r[1];
        }
        solve(rects);
    }
    return 0;
}