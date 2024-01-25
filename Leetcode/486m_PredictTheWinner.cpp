#include <iostream>
#include <vector>

// Algorithm 2.2 Game Trees - JeffE
// • A game state is good if either the current player has already won, or if the
// current player can move to a bad state for the opposing player.
// • A game state is bad if either the current player has already lost, or if every
// available move leads to a good state for the opposing player.
class Solution {
  public:
    bool predictTheWinner(std::vector<int>& nums) {
        this->nums = nums;
        return play(0, 0, nums.size() - 1, 1);
    }

    bool play(int score_diff, int left, int right, int player) {
        int next = -player;
        // Already won or lost
        if (right < left) {
            return (score_diff * player > 0) || (score_diff == 0 && player == 1);
        }

        // Pick left
        if (!play(score_diff + player * nums[left], left + 1, right, next)) {
            return true;
        }

        // Pick right
        if (!play(score_diff + player * nums[right], left, right - 1, next)) {
            return true;
        }

        return false;
    }

  private:
    std::vector<int> nums;
};

int main() {
    std::vector<int> nums = {1, 5, 2};
    Solution().predictTheWinner(nums);
}