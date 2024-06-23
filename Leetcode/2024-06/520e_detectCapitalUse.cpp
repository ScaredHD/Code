// 2024-06-23 每日一题
// [简单] 520. 检测大写字母

#include <string>

using std::string;

class Solution {
  public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) {
            return true;
        }

        auto isupper = [](char ch) {
            return ch > 64 && ch < 91;
        };

        bool isInitialUpper = isupper(word[0]);
        bool otherContainsUpper = false;
        bool otherContainsLower = false;
        for (int i = 1; i < word.size(); ++i) {
            if (isupper(word[i])) {
                otherContainsUpper = true;
            } else {
                otherContainsLower = true;
            }
        }

        if (isInitialUpper) {
            return (otherContainsUpper && !otherContainsLower) ||
                   (otherContainsLower && !otherContainsUpper);
        }

        return !otherContainsUpper;
    }
};