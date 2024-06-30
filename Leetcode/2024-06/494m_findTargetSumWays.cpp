// 2024-06-30 Sunday 09:47:56
// [中等] 494. 目标和

#include <numeric>
#include <vector>

using std::vector;

// class Solution {
//   public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         this->nums = nums;
//         return sumways(0, target);
//     }

//     int sumways(int i, int target) {
//         if (i == nums.size()) {
//             return target == 0;
//         }
//         return sumways(i + 1, target - nums[i]) + sumways(i + 1, target + nums[i]);
//     }

//     vector<int> nums;
// };

// ====== Solution 2: DP ======

class Solution {
  public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = std::accumulate(std::begin(nums), std::end(nums), 0);
        if (sum < target || (sum - target) % 2) {
            return 0;
        }

        int neg = (sum - target) / 2;
        vector<vector<int>> dp(2, vector<int>(neg + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 0; j < neg + 1; ++j) {
                dp[i % 2][j] = dp[(i - 1) % 2][j];
                if (nums[i - 1] <= j) {
                    dp[i % 2][j] += dp[(i - 1) % 2][j - nums[i - 1]];
                }
            }
        }

        return dp[nums.size() % 2][neg];
    }
};