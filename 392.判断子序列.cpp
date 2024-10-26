/*
 * @lc app=leetcode.cn id=392 lang=cpp
 * @lcpr version=20002
 *
 * [392] 判断子序列
 *
 * https://leetcode.cn/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (52.69%)
 * Likes:    1099
 * Dislikes: 0
 * Total Accepted:    496.7K
 * Total Submissions: 942.7K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 *
 *
 * 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 *
 * 进阶：
 *
 * 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T
 * 的子序列。在这种情况下，你会怎样改变代码？
 *
 * 致谢：
 *
 * 特别感谢 @pbrother 添加此问题并且创建所有测试用例。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "abc", t = "ahbgdc"
 * 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：s = "axc", t = "ahbgdc"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= s.length <= 100
 * 0 <= t.length <= 10^4
 * 两个字符串都只由小写字符组成。
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
    bool isSubsequence(string s, string t) {
        // vector<int> dp(s.size() + 1);

        // for (auto i = 1; i <= t.size(); i++) {
        //     auto pre = 0;
        //     for (auto j = 1; j <= s.size(); j++) {
        //         auto cur = dp[j];
        //         if (t[i - 1] == s[j - 1]) {
        //             dp[j] = pre + 1;
        //         } else {
        //             dp[j] = max(dp[j - 1], dp[j]);
        //         }

        //         pre = cur;
        //     }
        // }
        // // cout << dp[s.size()] << ' ' << s.size();
        // return dp[s.size()] == s.size();


        auto i = s.cbegin();
        auto j = t.cbegin();

        for (; i != s.end() && j != t.end(); ++j) {
            if (*i == *j) {
                i++;
            }
        }

        return i == s.end();
    }

};
// @lc code=end


/*
// @lcpr case=start
// "abc"\n"ahbgdc"\n
// @lcpr case=end

// @lcpr case=start
// "axc"\n"ahbgdc"\n
// @lcpr case=end

 */
