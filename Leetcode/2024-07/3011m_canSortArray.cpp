// 2024-07-13 Saturday 10:36:40
// [中等] 3011. 判断一个数组是否可以变为有序

#include <iostream>
#include <vector>

using std::vector;

class Solution {
  public:
    bool canSortArray(vector<int>& nums) {
        std::vector<std::pair<int, int>> minmax;

        int minInSeg = nums[0];
        int maxInSeg = nums[0];
        int curCount = count(nums[0]);
        for (int i = 0; i < nums.size(); ++i) {
            if (count(nums[i]) == curCount) {
                minInSeg = std::min(minInSeg, nums[i]);
                maxInSeg = std::max(maxInSeg, nums[i]);
            } else {
                minmax.emplace_back(minInSeg, maxInSeg);
                minInSeg = nums[i];
                maxInSeg = nums[i];
                curCount = count(nums[i]);
            }
        }
        minmax.emplace_back(minInSeg, maxInSeg);

        for (int i = 0; i < minmax.size() - 1; ++i) {
            if (minmax[i].second > minmax[i + 1].first) {
                return false;
            }
        }

        return true;
    }

    int count(int n) {
        int res = 0;
        while (n) {
            res += n % 2;
            n /= 2;
        }
        return res;
    }
};

int main() {
    vector v{20, 16, 4, 8};
    Solution().canSortArray(v);
}