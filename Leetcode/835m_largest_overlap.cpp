#include <map>
#include <vector>


// 2024-1-9
// Brute force for loop
class Solution {
  public:
    int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
        int n   = img1.size();
        int res = 0;
        for (int dx = -(n - 1); dx <= (n - 1); ++dx) {
            for (int dy = -(n - 1); dy <= (n - 1); ++dy) {
                int count = 0;
                for (int x = 0; x < n; ++x) {
                    for (int y = 0; y < n; ++y) {
                        if (img2[x][y] == 0) {
                            continue;
                        }
                        int x1 = x + dx;
                        int y1 = y + dy;
                        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n) {
                            if (img1[x1][y1] == 1) {
                                ++count;
                            }
                        }
                    }
                }
                res = std::max(res, count);
            }
        }
        return res;
    }
};

class Solution2 {
  public:
    int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
        std::map<std::pair<int, int>, int> overlapCount;
        int n = img1.size();
        for (int x1 = 0; x1 < n; ++x1) {
            for (int y1 = 0; y1 < n; ++y1) {
                for (int x2 = 0; x2 < n; ++x2) {
                    for (int y2 = 0; y2 < n; ++y2) {
                        if (img1[x1][y1] == 1 && img2[x2][y2] == 1) {
                            ++overlapCount[{x2 - x1, y2 - y1}];
                        }
                    }
                }
            }
        }

        int res = 0;
        for (const auto& p : overlapCount) {
            res = std::max(res, p.second);
        }
        return res;
    }
};

int main() {
    std::vector<std::vector<int>> img1 = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    std::vector<std::vector<int>> img2 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
    Solution().largestOverlap(img1, img2);
}