// 2024-07-06 Saturday 08:54:38
// [中等] 3101. 交替子数组计数

#include <numeric>
#include <vector>

using std::vector;

class Solution {
  public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        // dp[i] = number of alternating subarrays ending with nums[i],
        // that is AS in the form nums[k .. i].
        // for example: nums = [0, 1, 1, 1],
        // then dp[1] = 2, since nums[1, 1] and nums[0, 1] are AS.
        // dp[2] = 1, only nums[2, 2] is AS.

        vector<int> dp(nums.size(), 0);
        dp[0] = 1;

        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = 1;
            if (nums[i] != nums[i - 1]) {
                dp[i] += dp[i - 1];
            }
        }

        return std::accumulate(std::begin(dp), std::end(dp), 0LL);
    }
};