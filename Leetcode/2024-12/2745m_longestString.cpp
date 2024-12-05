// 2024-12-05 Thursday 16:41:56
// 2745[中等]. 构造最长的新字符串

#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>
#include <map>


class Solution {
public:
  int longestString(int x, int y, int z) { return 2 * (2 * std::min(x, y) + (x != y) + z); }
};

class Solution1 {
public:
  int longestString(int x, int y, int z) {
    int res = std::max({dfs(x - 1, y, z, 0), dfs(x, y - 1, z, 1), dfs(x, y, z - 1, 2)});
    return 2 * res;
  }

  int dfs(int x, int y, int z, int k) {
    if (x < 0 || y < 0 || z < 0) {
      return 0;
    }

    if (int res = memo[x][y][z][k]) {
      return res;
    }

    if (k == 0) {  // AA -> BB
      return memo[x][y][z][k] = 1 + dfs(x, y - 1, z, 1);
    }

    // BB, AB -> AA, AB
    return memo[x][y][z][k] = 1 + std::max(dfs(x - 1, y, z, 0), dfs(x, y, z - 1, 2));
  }


  std::array<std::array<std::array<std::array<int, 3>, 51>, 51>, 51> memo{};
};

