/*
 * @lc app=leetcode.cn id=115 lang=cpp
 * @lcpr version=20002
 *
 * [115] 不同的子序列
 *
 * https://leetcode.cn/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (52.56%)
 * Likes:    1279
 * Dislikes: 0
 * Total Accepted:    199.3K
 * Total Submissions: 379.3K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数，结果需要对 10^9 + 7 取模。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "rabbbit", t = "rabbit"
 * 输出：3
 * 解释：
 * 如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
 * rabbbit
 * rabbbit
 * rabbbit
 *
 * 示例 2：
 *
 * 输入：s = "babgbag", t = "bag"
 * 输出：5
 * 解释：
 * 如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length, t.length <= 1000
 * s 和 t 由英文字母组成
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
    int numDistinct(string s, string t) {
        // vector<vector<unsigned>> dp(s.size() + 1, vector<unsigned>(t.size() + 1));

        // for (auto i = 0; i <= s.size(); i++) {
        //     dp[i][0] = 1;
        // }

        // for (auto i = 1; i <= s.size(); i++) {
        //     for (auto j = 1; j <= t.size(); j++) {
        //         if (s[i - 1] == t[j - 1]) {
        //             dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

        //         } else {
        //             dp[i][j] = dp[i - 1][j];

        //         }
        //     }
        // }
        // return dp[s.size()][t.size()];


        vector<unsigned> dp(t.size() + 1);

        dp[0] = 1;

        for (auto i = 1; i <= s.size(); i++) {
            auto pre = dp[0];
            for (auto j = 1; j <= t.size(); j++) {
                auto cur = dp[j];
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = pre + dp[j];
                    // cout << dp[j] << ' ' << pre << endl;

                } else {
                    dp[j] = dp[j];

                }
                pre = cur;
            }
        }
        return dp[t.size()];
    }
};
// @lc code=end


/*
// @lcpr case=start
// "rabbbit"\n"rabbit"\n
// @lcpr case=end

// @lcpr case=start
// "babgbag"\n"bag"\n
// @lcpr case=end

 */
