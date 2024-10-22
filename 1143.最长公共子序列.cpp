/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 * @lcpr version=20002
 *
 * [1143] 最长公共子序列
 *
 * https://leetcode.cn/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (65.83%)
 * Likes:    1631
 * Dislikes: 0
 * Total Accepted:    527.8K
 * Total Submissions: 801.7K
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
 *
 * 一个字符串的 子序列
 * 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
 *
 *
 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
 *
 *
 * 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：text1 = "abcde", text2 = "ace"
 * 输出：3
 * 解释：最长公共子序列是 "ace" ，它的长度为 3 。
 *
 *
 * 示例 2：
 *
 * 输入：text1 = "abc", text2 = "abc"
 * 输出：3
 * 解释：最长公共子序列是 "abc" ，它的长度为 3 。
 *
 *
 * 示例 3：
 *
 * 输入：text1 = "abc", text2 = "def"
 * 输出：0
 * 解释：两个字符串没有公共子序列，返回 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= text1.length, text2.length <= 1000
 * text1 和 text2 仅由小写英文字符组成。
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
    int longestCommonSubsequence(string text1, string text2) {
        // // dp[i][j]：长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列为dp[i][j]
        // vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));


        // for (int i = 1; i <= text1.size(); i++) {
        //     for (int j = 1; j <= text2.size(); j++) {
        //         if (text1[i - 1] == text2[j - 1]) {
        //             dp[i][j] = dp[i - 1][j - 1] + 1;

        //         } else {
        //             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        //         }
        //     }
        // }

        // return dp[text1.size()][text2.size()];

        // 1维dp

        vector<int> dp(text2.size() + 1);

        for (int i = 1; i <= text1.size(); i++) {
            auto pre = 0;
            for (int j = 1; j <= text2.size(); j++) {
                auto cur = dp[j];
                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = pre + 1;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);

                }
                pre = cur;
            }
        }

        return dp[text2.size()];



    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcde"\n"ace"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"def"\n
// @lcpr case=end

 */
