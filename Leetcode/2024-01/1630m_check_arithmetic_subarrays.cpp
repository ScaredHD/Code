#include <algorithm>
#include <vector>

// 2024-1-7
class Solution {
  public:
    std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums,
                                               std::vector<int>& l,
                                               std::vector<int>& r) {
        std::vector<bool> res;
        for (int i{}; i < l.size(); ++i) {
            auto left  = nums.begin() + l[i];
            auto right = nums.begin() + r[i] + 1;
            std::vector<int> nums2{left, right};
            std::sort(nums2.begin(), nums2.end());
            res.push_back(check(nums2));
        }
        return res;
    }

    bool check(const std::vector<int>& nums) {
        int d = nums[1] - nums[0];
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i + 1] - nums[i] != d) {
                return false;
            }
        }
        return true;
    }
};

class Solution2 {
  public:
    std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums,
                                               std::vector<int>& l,
                                               std::vector<int>& r) {
        std::vector<bool> res;
        for (int i{}; i < l.size(); ++i) {
            res.push_back(check(nums, l[i], r[i]));
        }
        return res;
    }

    bool check(const std::vector<int>& nums, int l, int r) {
        int upper{nums[l]};
        int lower{nums[l]};
        for (int i = l; i <= r; ++i) {
            upper = std::max(upper, nums[i]);
            lower = std::min(lower, nums[i]);
        }

        if ((upper - lower) % (r - l)) {
            return false;
        }
        int d = (upper - lower) / (r - l);
        if (d == 0) {
            return true;
        }

        std::vector<int> arr(r - l + 1, 0);

        for (int i = l; i <= r; ++i) {
            if ((nums[i] - lower) % d) {
                return false;
            }
            ++arr[(nums[i] - lower) / d];
        }

        for (auto x : arr) {
            if (x != 1) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    std::vector<int> nums = {4, 6, 5, 9, 3, 7};
    std::vector<int> l    = {0, 0, 2};
    std::vector<int> r    = {2, 3, 5};

    Solution2().checkArithmeticSubarrays(nums, l, r);
}
