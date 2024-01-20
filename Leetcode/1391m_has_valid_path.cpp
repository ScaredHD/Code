#include <unordered_map>
#include <vector>

// 2024-1-20

class Solution {
  public:
    bool hasValidPath(std::vector<std::vector<int>>& grid) {
        m          = grid.size();
        n          = grid[0].size();
        this->grid = grid;
        vis        = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
        return dfs(0, 0, -1);
    }

    bool dfs(int x, int y, int from) {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return false;
        }

        if (vis[x][y]) {
            return false;
        }
        vis[x][y] = 1;

        auto dir = next_dir[grid[x][y]];
        if (from != -1 && dir[0] != from && dir[1] != from) {
            vis[x][y] = 0;
            return false;
        }

        if (x == m - 1 && y == n - 1) {
            return true;
        }

        for (int i = 0; i < 2; ++i) {
            int to        = dir[i];
            auto [dx, dy] = diff[to];
            if (dfs(x + dx, y + dy, opposite(to))) {
                return true;
            }
        }

        vis[x][y] = 0;
        return false;
    }

    int opposite(int dir) { return (dir + 2) % 4; }

  private:
    int m;
    int n;
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> vis;
    std::vector<std::pair<int, int>> diff{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    std::vector<std::vector<int>> next_dir{{}, {1, 3}, {0, 2}, {1, 2}, {2, 3}, {0, 1}, {0, 3}};
};

int main() {
    std::vector<std::vector<int>> grid{{4, 1}, {6, 1}};
    Solution().hasValidPath(grid);
}