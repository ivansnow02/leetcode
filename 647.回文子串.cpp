/*
 * @lc app=leetcode.cn id=647 lang=cpp
 * @lcpr version=20002
 *
 * [647] 回文子串
 *
 * https://leetcode.cn/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (67.64%)
 * Likes:    1380
 * Dislikes: 0
 * Total Accepted:    362K
 * Total Submissions: 535.1K
 * Testcase Example:  '"abc"'
 *
 * 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
 *
 * 回文字符串 是正着读和倒过来读一样的字符串。
 *
 * 子字符串 是字符串中的由连续字符组成的一个序列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 *
 *
 * 示例 2：
 *
 * 输入：s = "aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 由小写英文字母组成
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
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(s.size() + 1));
        int ans = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            auto pre = dp;
            for (int j = i; j < s.size(); ++j) {
                if (s[i] != s[j])
                    continue;
                if (j - i <= 2) {
                    dp[i][j] = true;
                    ans++;

                } else if (dp[i + 1][j - 1] == true) {
                    dp[i][j] = true;
                    ans ++;
                }

            }
        }
        return ans;
    }

};
// @lc code=end


/*
// @lcpr case=start
// "abc"\n
// @lcpr case=end

// @lcpr case=start
// "aaa"\n
// @lcpr case=end

 */
