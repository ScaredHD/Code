// 2024-07-05 Friday 09:28:10
// [简单] 3033. 修改矩阵

#include <vector>

using std::vector;

class Solution {
  public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> maxelem(n);
        for (int col = 0; col < n; ++col) {
            for (int row = 0; row < m; ++row) {
                maxelem[col] = std::max(maxelem[col], matrix[row][col]);
            }
        }

        auto res = matrix;
        for (int col = 0; col < n; ++col) {
            for (int row = 0; row < m; ++row) {
                res[row][col] = matrix[row][col] >= 0 ? matrix[row][col] : maxelem[col];
            }
        }

        return res;
    }
};