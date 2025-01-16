/*
 * @lc app=leetcode.cn id=738 lang=cpp
 * @lcpr version=20004
 *
 * [738] 单调递增的数字
 *
 * https://leetcode.cn/problems/monotone-increasing-digits/description/
 *
 * algorithms
 * Medium (51.31%)
 * Likes:    503
 * Dislikes: 0
 * Total Accepted:    137.4K
 * Total Submissions: 267.8K
 * Testcase Example:  '10'
 *
 * 当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。
 *
 * 给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。
 *
 *
 *
 * 示例 1:
 *
 * 输入: n = 10
 * 输出: 9
 *
 *
 * 示例 2:
 *
 * 输入: n = 1234
 * 输出: 1234
 *
 *
 * 示例 3:
 *
 * 输入: n = 332
 * 输出: 299
 *
 *
 *
 *
 * 提示:
 *
 *
 * 0 <= n <= 10^9
 *
 *
 */


// @lcpr-template-start
#include <cstddef>
#include <string>
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
    int monotoneIncreasingDigits(int n) {
        auto s = to_string(n);
        auto first_9_index = s.size();
        for (int i = s.size() - 1; i > 0; i--) {
            if (s[i - 1] > s[i]) {
                s[i - 1]--;
                first_9_index = i;
            }
        }
        for (int i = first_9_index; i < s.size(); i++) {
            s[i] = '9';
        }
        return stoi(s);
    }
};
// @lc code=end


/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 1234\n
// @lcpr case=end

// @lcpr case=start
// 332\n
// @lcpr case=end

 */
