#include "MyHeaders.hpp"
using namespace std;
/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode.cn/problems/integer-break/description/
 *
 * algorithms
 * Medium (63.81%)
 * Likes:    1408
 * Dislikes: 0
 * Total Accepted:    361.6K
 * Total Submissions: 565.6K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >=
 * 2 ），并使这些整数的乘积最大化。
 *
 * 返回 你可以获得的最大乘积 。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: n = 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 *
 * 示例 2:
 *
 *
 * 输入: n = 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 *
 *
 *
 * 提示:
 *
 *
 * 2 <= n <= 58
 *
 *
 */

// @lc code=start
class Solution {
public:
  int integerBreak(int n) {
    vector<int> dp(n + 1); // 分拆数字i，可以得到的最大乘积为dp[i]。
    dp[2] = 1;             // 0和1没法分割
    for (auto i = 3; i <= n; i++) {
      for (
          auto j = 1; j <= i / 2;
          j++) { // 拆分一个数n使之乘积最大，一定是拆分成m个近似相同的子数相乘才是最大的
        dp[i] = max({dp[i], j * (i - j), j * dp[i - j]}); // 找到最大的dp[i]
      }
    }
    return dp[n];
  }
};
// @lc code=end
