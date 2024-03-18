#include <vector>

using std::vector;

// 2024-3-18

class Solution {
  public:
    int semiOrderedPermutation(vector<int>& nums) {
        int indexOfOne{};
        int indexOfLast{};

        int n = nums.size();
        for (int i{}; i < n; ++i) {
            if (nums[i] == 1) {
                indexOfOne = i;
            }
            if (nums[i] == n) {
                indexOfLast = i;
            }
        }

        int res = indexOfOne + (n - 1) - indexOfLast;
        return indexOfLast < indexOfOne ? res - 1 : res;
    }
};