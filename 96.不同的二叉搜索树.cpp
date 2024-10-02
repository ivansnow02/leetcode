#include "MyHeaders.hpp"
using namespace std;
/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode.cn/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (71.24%)
 * Likes:    2552
 * Dislikes: 0
 * Total Accepted:    470.1K
 * Total Submissions: 659.4K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树
 * 有多少种？返回满足题意的二叉搜索树的种数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：5
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 *
 *
 */

// @lc code=start
class Solution {
public:
  int numTrees(int n) {
    vector<int> dp(n + 1); // dp[i]：元素为i个的二叉搜索树个数
    dp[0] = 1; // 空树也是一个二叉树
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        // j-1 为j为头结点左子树节点数量，
        // i-j 为以j为头结点右子树节点数量
        dp[i] += dp[i - j] * dp[j - 1];
      }
    }
    return dp[n];
  }
};
// @lc code=end
