
/*
 * @lc app=leetcode.cn id=279 lang=cpp
 * @lcpr version=20000
 *
 * [279] 完全平方数
 *
 * https://leetcode.cn/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (67.42%)
 * Likes:    2043
 * Dislikes: 0
 * Total Accepted:    590.2K
 * Total Submissions: 875.5K
 * Testcase Example:  '12'
 *
 * 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
 *
 * 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16
 * 都是完全平方数，而 3 和 11 不是。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 12
 * 输出：3
 * 解释：12 = 4 + 4 + 4
 *
 * 示例 2：
 *
 * 输入：n = 13
 * 输出：2
 * 解释：13 = 4 + 9
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^4
 *
 *
 */


// @lcpr-template-start
#include <cmath>
#include <limits>
using namespace std;
#include <algorithm>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<unsigned> dp(n + 1, numeric_limits<unsigned>::max());
        dp[0] = 0;
        for (auto i = 1; i <= sqrt(n); i++) {
            for (auto j = i * i; j <= n; j++) {
                dp[j] = ranges::min(dp[j - i * i] + 1, dp[j]);

            }
        }
        return dp[n];
    }
};
// @lc code=end


/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

 */
