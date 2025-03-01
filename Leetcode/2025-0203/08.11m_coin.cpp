// 2025/03/01 Saturday 16:20:53
// [中等] 面试题 08.11. 硬币

#include <vector>

class Solution
{
public:
  int waysToChange(int n)
  {
    std::vector<int> coins = {1, 5, 10, 25};
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    const int mod = 1e9 + 7;

    // 外层从小到大遍历面额
    for (int coin : coins) {
      // 内层处理某种面额时, 比它小的面额的硬币情况已经被处理过了
      // 如当前遍历10分硬币, 此时 dp 已经记录了使用较小硬币面额的两种情况:
      //    - 只使用 1 分: {1}
      //    - 只使用 1 和 5 分: {1, 5}
      // 因此不会重复计算 1 + 5 和 5 + 1, 只有前者被考虑进去
      // 遍历到 dp[k] 时, dp[0..k-1] 已经考虑的 {1}, {1, 5}, {1, 5, 10} 的情况
      for (int i = coin; i <= n; ++i) {
        dp[i] = (dp[i] + dp[i - coin]) % mod;
      }
    }
    return dp[n];
  }
};