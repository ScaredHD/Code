// 2025/03/03 Monday 09:58:53
// [中等] 2517. 礼盒的最大甜蜜度

#include <algorithm>
#include <vector>


using namespace std;


class Solution
{
public:
  int maximumTastiness(vector<int>& price, int k)
  {
    std::sort(begin(price), end(price));
    int lo = 0;
    int hi = price.back() - price.front();
    while (lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;
      if (check(price, k, mid)) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    return lo;
  }

  bool check(const vector<int>& price, int k, int dist)
  {
    int count = 1;
    int last = 0;
    for (int i = 1; i < price.size(); ++i) {
      if (price[i] - price[last] >= dist) {
        ++count;
        last = i;
      }
    }
    return count >= k;
  }
};