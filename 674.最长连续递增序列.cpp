/*
 * @lc app=leetcode.cn id=674 lang=cpp
 * @lcpr version=20002
 *
 * [674] 最长连续递增序列
 *
 * https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/
 *
 * algorithms
 * Easy (58.09%)
 * Likes:    467
 * Dislikes: 0
 * Total Accepted:    270.2K
 * Total Submissions: 465.1K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
 *
 * 连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1]
 * ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,3,5,4,7]
 * 输出：3
 * 解释：最长连续递增序列是 [1,3,5], 长度为3。
 * 尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,2,2,2,2]
 * 输出：1
 * 解释：最长连续递增序列是 [2], 长度为1。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */


// @lcpr-template-start
#include <limits>
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
    int findLengthOfLCIS(vector<int> &nums) {
        // dp
        if (nums.size() == 1)
            return 1;

        // vector<int> dp(nums.size(), 1);
        // int res = numeric_limits<int>::min();
        // for (int i = 1; i < nums.size(); i++) {
        //     if (nums[i] > nums[i - 1])
        //         dp[i] = dp[i - 1] + 1;
        //     res = max(res, dp[i]);

        // }


        // two pointer

        int res = 0;
        for (int i = 1, j = 0; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                j = i;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
// @lc code=end


/*
// @lcpr case=start
// [1,3,5,4,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n
// @lcpr case=end

 */
