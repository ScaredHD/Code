#include <algorithm>
#include <vector>

using std::vector;

class Solution {
  public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int len = 0;
        int res = 0;
        for (int i = 1; i < temperatureA.size(); ++i) {
            auto trendA = (temperatureA[i] <=> temperatureA[i - 1]);
            auto trendB = (temperatureB[i] <=> temperatureB[i - 1]);
            if (trendA == trendB) {
                res = std::max(res, ++len);
            } else {
                len = 0;
            }
        }
        return res;
    }
};

int main() {
    vector<int> temperatureA = {21, 18, 18, 18, 31};
    vector<int> temperatureB = {34, 32, 16, 16, 17};
    Solution().temperatureTrend(temperatureA, temperatureB);
}