/*
 * @lc app=leetcode.cn id=72 lang=cpp
 * @lcpr version=20002
 *
 * [72] 编辑距离
 *
 * https://leetcode.cn/problems/edit-distance/description/
 *
 * algorithms
 * Medium (63.22%)
 * Likes:    3525
 * Dislikes: 0
 * Total Accepted:    558.3K
 * Total Submissions: 883.1K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
 *
 * 你可以对一个单词进行如下三种操作：
 *
 *
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 *
 *
 * 示例 2：
 *
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= word1.length, word2.length <= 500
 * word1 和 word2 由小写英文字母组成
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
    int minDistance(string word1, string word2) {
        vector<vector<unsigned>> dp(word1.size() + 1, vector<unsigned>(word2.size() + 1));

        for (auto i = 0; i <= word1.size(); ++i) {
            dp[i][0] = i;
        }
        for (auto j = 0; j <= word2.size(); ++j) {
            dp[0][j] = j;
        }

        for (auto i = 1; i <= word1.size(); ++i) {
            for (auto j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // the two words are same, no operation needed

                } else {
                    dp[i][j] = min({
                                       dp[i - 1][j], // delete one letter in word1
                                       dp[i][j - 1], // delete one letter in word2
                                       dp[i - 1][j - 1] // replace one words
                               }) +
                               1;

                }
            }
        }
        return dp[word1.size()][word2.size()];
    }

};
// @lc code=end


/*
// @lcpr case=start
// "horse"\n"ros"\n
// @lcpr case=end

// @lcpr case=start
// "intention"\n"execution"\n
// @lcpr case=end

 */
