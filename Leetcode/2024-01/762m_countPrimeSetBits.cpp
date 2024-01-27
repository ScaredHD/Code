#include <iostream>

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for (int i = left; i <= right; ++i) {
            if (isPrime(__builtin_popcount(i))) {
                ++res;
            }
        }
        return res;
    }

    bool isPrime(int num) {
        if (num == 1) return false;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    for (int i = 1; i < 20; ++i) {
        if (Solution().isPrime(i)) {
            std::cout << i << "\n";
        }
    }
}