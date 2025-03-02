// 2025/03/02 Sunday 13:55:43
// [中等] 2178. 拆分成最多数目的正偶数之和

#include <vector>

using namespace std;

class Solution
{
public:
  vector<long long> maximumEvenSplit(long long target)
  {
    if (target % 2)
      return {};

    long long sum = 0;
    vector<long long> v;
    int i = 1;
    while (sum < target) {
      v.push_back(2 * i);
      sum += 2 * i;
      ++i;
    }
    if (sum > target) {
      int idx = (sum - target) / 2 - 1;
      v.erase(v.begin() + idx);
    }
    return v;
  }
};