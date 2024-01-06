#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// 2024-1-6
class Solution {
  public:
    int similarPairs(std::vector<std::string>& words) {
        std::unordered_map<int, int> rec;
        for (const auto& word : words) {
            ++rec[encode(word)];
        }

        int res{};
        for (const auto& r : rec) {
            int n = r.second;
            if (n > 1) {
                res += n * (n - 1) / 2;
            }
        }
        return res;
    }

    int encode(const std::string& str) {
        int code = 0;
        for (char ch : str) {
            int digit = ch - 'a';
            code |= (1 << digit);
        }
        return code;
    }
};

int main() {
    int e1 = Solution().encode("abc");
    int e2 = Solution().encode("ab");
    int e3 = Solution().encode("bc");
    int e4 = Solution().encode("ac");
    int e5 = Solution().encode("b");
    int i = 42;
}