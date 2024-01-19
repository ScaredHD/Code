#include <string>
#include <iostream>

// 2024-1-19
class Solution {
  public:
    std::string countAndSay(int n) { return n == 1 ? "1" : describe(countAndSay(n - 1)); }

    std::string describe(const std::string& number) {
        int l = 0;
        int r = 0;
        std::string res;

        while (l < number.size()) {
            while (number[r] == number[l]) {
                ++r;
            }
            res += std::to_string(r - l) + number[l];
            l = r;
        }

        return res;
    }
};

int main() {
    std::cout << Solution().describe("11") << "\n";
    std::cout << Solution().describe("21") << "\n";
    std::cout << Solution().describe("1211") << "\n";
    std::cout << Solution().describe("111221") << "\n";
}