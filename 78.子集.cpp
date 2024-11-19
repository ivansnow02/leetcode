/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=20003
 *
 * [78] 子集
 *
 * https://leetcode.cn/problems/subsets/description/
 *
 * algorithms
 * Medium (81.79%)
 * Likes:    2389
 * Dislikes: 0
 * Total Accepted:    889.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 *
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * nums 中的所有元素 互不相同
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
    vector<vector<int>> result;
    vector<int> path;
    void backTrack(vector<int> &nums, int start) {
        result.emplace_back(path);
        if (start >= nums.size()) {

            return;
        }
        for (int i = start; i < nums.size(); i++) {
            path.emplace_back(nums[i]);
            backTrack(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        backTrack(nums, 0);
        return result;
    }
};
// @lc code=end


/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
