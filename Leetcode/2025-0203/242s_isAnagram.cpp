// 2025-02-25 Tuesday 09:57:58
// [简单] 242. 有效的字母异位词

#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    std::sort(begin(s), end(s));
    std::sort(begin(t), end(t));
    return s == t;
  }

  bool isAnagram2(string s, string t)
  {
    std::unordered_map<char, int> letters1;
    for (auto ch : s) {
      ++letters1[ch];
    }

    std::unordered_map<char, int> letters2;
    for (auto ch : t) {
      ++letters2[ch];
    }

    if (letters1.size() != letters2.size()) {
      return false;
    }

    for (auto [ch, count] : letters1) {
      if (letters2[ch] != count) {
        return false;
      }
    }
    return true;
  }
};