// 2024-12-04 Wednesday 13:39:30 - 14:07:44
// [中等] 1347. 制造字母异位词的最小步骤数

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
  int minSteps(string s, string t) {
    unordered_map<int, int> freqS;  // char frequency of s
    for (char ch : s) {
      ++freqS[ch - 'a'];
    }

    int res = 0;
    for (char ch : t) {
      if (freqS[ch - 'a'] != 0) {
        --freqS[ch - 'a'];
      } else {
        ++res;
      }
    }
    return res;
  }
};
