// 2024-08-14 Wednesday 17:32:45
// [中等] 3152. 特殊数组 II

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<bool> isArraySpecial(vector<int>& a, vector<vector<int>>& queries) {
        auto n = a.size();
        vector<int> dp(n, 1);
        for (int j = 1; j < n; ++j) {
            if (a[j] % 2 != a[j - 1] % 2) {
                dp[j] = dp[j - 1] + 1;
            }
        }
        vector<bool> res;
        res.reserve(queries.size());
        for (auto& p : queries) {
            res.push_back(p[1] - p[0] + 1 <= dp[p[1]]);
        }
        return res;
    }
};