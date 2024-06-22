// 2024-06-22 每日一题
// [困难] 2663. 字典序最小的美丽字符串

#include <string>

using std::string;

class Solution {
  public:
    string smallestBeautifulString(string s, int k) {
        int bound = 'a' + k;

        for (int i = s.size() - 1; i >= 0; --i) {
            for (char after = s[i] + 1; after < bound && after < s[i] + 4; ++after) {
                if ((i > 0 && s[i - 1] == after) || (i > 1 && s[i - 2] == after)) {
                    continue;
                }

                s[i] = after;
                return minimizeTail(s, i + 1);
            }
        }
        return {};
    }

    string minimizeTail(string s, int idx) {
        for (int i = idx; i < s.size(); ++i) {
            for (char ch = 'a'; ch < 'd'; ++ch) {
                if ((i > 0 && s[i - 1] == ch) || (i > 1 && s[i - 2] == ch)) {
                    continue;
                }
                s[i] = ch;
                break;
            }
        }
        return s;
    }
};