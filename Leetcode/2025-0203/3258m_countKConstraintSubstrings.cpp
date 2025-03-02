
// [简单] 3258. 统计满足 K 约束的子字符串数量 I

#include <array>
#include <string>


using namespace std;

class Solution
{
public:
  int countKConstraintSubstrings(string s, int k)
  {
    auto n = s.size();
    int i = 0;
    std::array<int, 2> count;
    int res = 0;
    for (int j = 0; j < n; ++j) {
      ++count[s[j] - '0'];
      while (count[0] > k && count[1] > k) {
        --count[s[i] - '0'];
        ++i;
      }
      res += j - i + 1;
    }
    return res;
  }
};