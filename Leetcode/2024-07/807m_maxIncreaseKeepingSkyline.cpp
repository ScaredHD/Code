// 2024-07-14 Sunday 10:21:20
// [中等] 807. 保持城市天际线

#include <vector>

using std::vector;

class Solution {
  public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> rowMax(n, -1);
        vector<int> colMax(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMax[i] = std::max(rowMax[i], grid[i][j]);
                colMax[j] = std::max(colMax[j], grid[i][j]);
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res += std::min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }
        return res;
    }
};