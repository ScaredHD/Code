#include <vector>

class Solution {
  public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        m   = matrix.size();
        n   = matrix.front().size();
        vis = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));

        std::vector<int> res;
        int dir = 0;
        int i   = 0;
        int j   = 0;
        for (int count = 0; count < m * n; ++count) {
            vis[i][j] = 1;
            res.push_back(matrix[i][j]);

            for (int next = 0; next < 4; ++next) {
                int nextdir   = (dir + next) % 4;
                auto [di, dj] = delta(nextdir);
                if (check(i + di, j + dj)) {
                    dir = nextdir;
                    i += di;
                    j += dj;
                    break;
                }
            }
        }
        return res;
    }

    std::pair<int, int> delta(int dir) {
        switch (dir) {
            case 0:  // left
                return {0, 1};
            case 1:  // down
                return {1, 0};
            case 2:  // right
                return {0, -1};
            case 3:  // up
                return {-1, 0};
            default:
                return {0, 0};
        }
    }

    bool check(int i, int j) { return (i >= 0 && i < m) && (j >= 0 && j < n) && !vis[i][j]; }

  private:
    int m;
    int n;
    std::vector<std::vector<int>> vis;
};

class Solution2 {
  public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        m   = matrix.size();
        n   = matrix.front().size();
        vis = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
        mat = matrix;
        return spiral(0, 0, 0);
    }

    std::vector<int> spiral(int i, int j, int dir) {
        if (!check(i, j)) {
            return {};
        }

        vis[i][j] = 1;
        std::vector<int> res{};
        for (int d = 0; d < 4; ++d) {
            int nextdir   = (dir + d) % 4;
            auto [di, dj] = delta(nextdir);
            res = spiral(i + di, j + dj, nextdir);
            if (!res.empty()) {
                break;
            }
        }
        res.insert(res.begin(), mat[i][j]);
        return res;
    }

    std::pair<int, int> delta(int dir) {
        switch (dir) {
            case 0:  // left
                return {0, 1};
            case 1:  // down
                return {1, 0};
            case 2:  // right
                return {0, -1};
            case 3:  // up
                return {-1, 0};
            default:
                return {0, 0};
        }
    }

    bool check(int i, int j) { return (i >= 0 && i < m) && (j >= 0 && j < n) && !vis[i][j]; }

  private:
    int m;
    int n;
    std::vector<std::vector<int>> vis;
    std::vector<std::vector<int>> mat;
};

int main() {
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Solution().spiralOrder(matrix);
}