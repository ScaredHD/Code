#include <vector>
#include <string>

// 2024-1-10
class Solution {
public:
    std::vector<std::string> simplifiedFractions(int n) {
        std::vector<std::string> res;
        for (int denominator = 2; denominator <= n; ++denominator) {
            for (int numerator = 1; numerator < denominator; ++numerator) {
                if (gcd(denominator, numerator) == 1) {
                    res.push_back(std::to_string(numerator) + "/" + std::to_string(denominator));
                }
            }
        }
        return res;
    }

    int gcd(int a, int b) {
        if (a < b) {
            std::swap(a, b);
        }

        for (int r = a % b; r != 0; r = a % b) {
            a = b;
            b = r;
        }
        
        return b;
    }
};
