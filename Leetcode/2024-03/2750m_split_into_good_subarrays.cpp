#include <vector>

// 2024-3-17

using std::vector;

class Solution {
  public:
    // Split into one-hot arrays
    // (ab) mod n = [(a mod n)(b mod n)] mod n
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int prev = -1;
        int res = 1;
        long long n = 1'000'000'007;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (prev != -1) {
                    res = (res * ((i - prev) % n)) % n;
                }
                prev = i;
            }
        }
        return prev == -1 ? 0 : res;
    }
};