/*
 * @lc app=leetcode.cn id=516 lang=cpp
 * @lcpr version=20002
 *
 * [516] 最长回文子序列
 *
 * https://leetcode.cn/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (67.32%)
 * Likes:    1258
 * Dislikes: 0
 * Total Accepted:    266.3K
 * Total Submissions: 395.6K
 * Testcase Example:  '"bbbab"'
 *
 * 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
 *
 * 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "bbbab"
 * 输出：4
 * 解释：一个可能的最长回文子序列为 "bbbb" 。
 *
 *
 * 示例 2：
 *
 * 输入：s = "cbbd"
 * 输出：2
 * 解释：一个可能的最长回文子序列为 "bb" 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 仅由小写英文字母组成
 *
 *
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<unsigned>> dp(s.size() + 1, vector<unsigned>(s.size() + 1));

        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = 1;
        }
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i + 1; j < s.size(); ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;

                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);

                }
            }
        }

        return dp[0][s.size() - 1]; // from 0 to s.size()-1, the whole string

    }
};
// @lc code=end


/*
// @lcpr case=start
// "bbbab"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
