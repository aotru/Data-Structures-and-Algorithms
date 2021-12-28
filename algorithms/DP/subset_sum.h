#include <vector>
using namespace std;



inline bool subset_sum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<bool>> memo(n + 1, vector<bool>(target + 1));

    // memo[n][x] = can we get a subset that adds up to x with the first n numbers in nums

    // Base Case #1: target = 0 
    for (int row = 0; row <= n; ++row) {
        memo[row][0] = true;
    }

    // Base Case #2: n = 0, target != 0
    for (int col = 1; col <= target; ++col) {
        memo[0][col] = false;
    }

    for (int i = 1; i <= n; ++i) {
        for (int curr_target = 1; curr_target <= target; ++curr_target) {
            memo[i][curr_target] = memo[i - 1][curr_target];
            if (curr_target >= nums[i - 1]) { // minus one because of 0-based indexing
                memo[i][curr_target] = memo[i - 1][curr_target] or memo[i - 1][curr_target - nums[i - 1]];
            }
        }
    }

    return memo[n][target];
}

