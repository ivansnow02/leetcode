#include <algorithm>
#include <limits>
#include "MyHeaders.hpp"
using namespace std;
/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=20000
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<unsigned> dp(amount + 1, numeric_limits<int>::max());
        dp[0] = 0;
        for (const auto &coin: coins) {
            for (auto j = coin; j <= amount; j++) {
                dp[j] = ranges::min(dp[j - coin] + 1, dp[j]);

            }
        }
        return dp[amount] != numeric_limits<int>::max() ? dp[amount] : -1;


    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */
