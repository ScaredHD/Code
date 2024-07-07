// 2024-07-07 Sunday 09:35:51
// [简单] 1958. 检查操作是否合法

#include <vector>

using std::vector;

class Solution {
  public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int m = board.size();
        int n = board[0].size();

        // board[rMove][cMove] = color;

        vector<int> dxs = {-1, 0, 1, -1, 1, -1, 0, 1};
        vector<int> dys = {-1, -1, -1, 0, 0, 1, 1, 1};

        // 8 directions
        for (int k = 0; k < 8; ++k) {
            int dx = dxs[k];
            int dy = dys[k];

            // check for good lines
            int i = rMove + dx;
            int j = cMove + dy;
            int len = 2;
            while (i >= 0 && i < m && j >= 0 && j < n) {
                if (board[i][j] == '.') {
                    break;
                }

                if (board[i][j] == color) {
                    if (len > 2) {
                        return true;
                    }
                    break;
                }

                ++len;
                i += dx;
                j += dy;
            }
        }

        return false;
    }
};

// [["W",".","W","B","B",".","B","W"],
//  [".","W","B",".",".",".",".","W"],
//  ["W",".",".","B","W","B","B","."],
//  [".","W",".","W","B","W","B","W"],
//  [".","W",".",".","B","B",".","W"],
//  [".",".","W","W","W","W","W","B"],
//  ["W","B","B",".",".",".","B","."],
//  ["B","W","W","W",".","B","B","W"]]