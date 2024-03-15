#include <string>
#include <vector>

// 2024-3-15

using std::string;
using std::to_string;
using std::vector;

class Solution {
  public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int left = 0;
        for (int right = left; right < nums.size();) {
            if (right < nums.size() - 1 && (long long)nums[right + 1] - nums[left] == right - left + 1) {
                // right + 1 is in the interval
                ++right;
            } else {
                // [left, right] is the interval
                res.push_back(to_string(nums[left]));
                if (right - left > 0) {
                    res.back() += "->" + to_string(nums[right]);
                }
                left = ++right;
            }
        }
        return res;
    }
};

int main() {}