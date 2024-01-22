#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

// 2024-1-22
class Solution {
  public:
    int maximizeSquareHoleArea(int n, int m, std::vector<int>& hBars, std::vector<int>& vBars) {
        std::sort(hBars.begin(), hBars.end());
        std::sort(vBars.begin(), vBars.end());

        int start = 0;
        int hmax  = 0;
        for (int i = 0; i < hBars.size(); ++i) {
            if (hBars[i] - hBars[start] != i - start) {
                hmax  = std::max(hmax, i - start);
                start = i;
            }
        }
        hmax = std::max(hmax, (int)hBars.size() - start);

        start    = 0;
        int vmax = 0;
        for (int i = 0; i < vBars.size(); ++i) {
            if (vBars[i] - vBars[start] != i - start) {
                vmax  = std::max(vmax, i - start);
                start = i;
            }
        }
        vmax = std::max(vmax, (int)vBars.size() - start);

        int l = std::min(hmax, vmax) + 1;
        return l * l;
    }
};

int main() {
    std::vector<int> hBars = {3, 2};
    std::vector<int> vBars = {4, 2};
    std::cout << Solution().maximizeSquareHoleArea(2, 4, hBars, vBars);
}