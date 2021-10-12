#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct DisjointSet {
    size_t len;
    vector<int> par;
    vector<int> rank;
    void init(int n) {
        rank = vector<int>(n, 0);
        par.resize(len = n);
        for (int i = 0; i < n; ++i) { par[i] = i; }
    }

    int find(int x) { return (par[x] == x ? x : par[x] = find(par[x])); }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) {
            par[px] = py;
        } else {
            par[py] = px;
        }
        if (rank[px] == rank[py]) ++rank[px];
    }

    bool same(int x, int y) { return find(x) == find(y); }

    void info() {
        vector<vector<int>> grp(len);
        vector<int> isVisited(len, 0);
        for (int i = 0; i < len; ++i)
            if (!isVisited[i]) { grp[find(i)].push_back(i); }

        for (auto it = grp.begin(); it != grp.end(); ++it) {
            if (!it->empty()) {
                printf("[%d]  ", it - grp.begin());
                for (auto&& i : *it) { cout << i << " "; }
                cout << "\n";
            }
        }
    }
};

int main() {
    ifstream ifs("D:\\Programming\\draft.txt");
    int n, k;
    ifs >> n >> k;
    vector<int> T(n);
    vector<int> X(n);
    vector<int> Y(n);
    for (int i = 0; i < k; ++i) { ifs >> T[i] >> X[i] >> Y[i]; }

    DisjointSet s;
    s.init(3 * n);

    int ans = 0;
    for (int i = 0; i < k; ++i) {
        int t = T[i];
        int x = X[i] - 1;
        int y = Y[i] - 1;

        if (x < 0 || x >= n || y < 0 || y >= n) {
            ++ans;
            continue;
        }

        if (t == 1) {
            // (xA, yB) || (xA, yC)
            if (s.same(x, y + n) || s.same(x, y + 2 * n)) {
                ++ans;
            } else {
                s.unite(x, y);                  // (xA, yA)
                s.unite(x + n, y + n);          // (xB, yB)
                s.unite(x + 2 * n, y + 2 * n);  // (xC, yC)
            }
        }

        if (t == 2) {
            // (xA, yA) || (xA, yC)
            if (s.same(x, y) || s.same(x, y + 2 * n)) {
                ++ans;
            } else {
                s.unite(x, y + n);          // (xA, yB)
                s.unite(x + n, y + 2 * n);  // (xB, yC)
                s.unite(x + 2 * n, y);      // (xC, yA)
            }
        }
    }

    cout << ans;
}