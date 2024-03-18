#include <algorithm>
#include <vector>


using std::vector;

// 2024-3-18

class Solution {
  public:
    int findValueOfPartition(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int mindiff = nums[1] - nums[0];
        for (int i = 0; i < nums.size() - 1; ++i) {
            mindiff = std::min(mindiff, nums[i + 1] - nums[i]);
        }
        return mindiff;
    }
};