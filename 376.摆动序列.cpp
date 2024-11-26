/*
 * @lc app=leetcode.cn id=376 lang=cpp
 * @lcpr version=20003
 *
 * [376] 摆动序列
 *
 * https://leetcode.cn/problems/wiggle-subsequence/description/
 *
 * algorithms
 * Medium (46.22%)
 * Likes:    1178
 * Dislikes: 0
 * Total Accepted:    264.7K
 * Total Submissions: 572.6K
 * Testcase Example:  '[1,7,4,9,2,5]'
 *
 * 如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列
 * 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。
 *
 *
 *
 * 例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。
 *
 * 相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5]
 * 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
 *
 *
 * 子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。
 *
 * 给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,7,4,9,2,5]
 * 输出：6
 * 解释：整个序列均为摆动序列，各元素之间的差值为 (6, -3, 5, -7, 3) 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,17,5,10,13,15,10,5,16,8]
 * 输出：7
 * 解释：这个序列包含几个长度为 7 摆动序列。
 * 其中一个是 [1, 17, 10, 13, 10, 16, 8] ，各元素之间的差值为 (16, -7, 3, -3, 6, -8) 。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1,2,3,4,5,6,7,8,9]
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 1000
 *
 *
 *
 *
 * 进阶：你能否用 O(n) 时间复杂度完成此题?
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
    int wiggleMaxLength(vector<int> &nums) {
        // if (nums.size() <= 1)
        //     return nums.size();

        // // 贪心
        // int pre_diff = 0;
        // int cur_diff = 0;
        // int cnt = 1;
        // for (int i = 0; i < nums.size() - 1; i++) {
        //     cur_diff = nums[i + 1] - nums[i];
        //     if ((pre_diff <= 0 && cur_diff > 0) || (pre_diff >= 0 && cur_diff < 0)) {
        //         cnt++;
        //         pre_diff = cur_diff;
        //     }
        // }

        // return cnt;

        // dp

        // dp[i][0] 表示考虑前 i 个数，第 i 个数作为山峰的摆动子序列的最长长度
        // dp[i][1] 表示考虑前 i 个数，第 i 个数作为山谷的摆动子序列的最长长度
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2));

        dp[0][0] = dp[0][1] = 1;

        for (int i = 1; i < nums.size(); i++) {
            dp[i][0] = dp[i][1] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] < nums[j]) {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }

                if (nums[i] > nums[j]) {
                    // 把nums[i]接在前面的某个山谷后面
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
            }


        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);




    }
};
// @lc code=end


/*
// @lcpr case=start
// [1,7,4,9,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,17,5,10,13,15,10,5,16,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7,8,9]\n
// @lcpr case=end

 */
