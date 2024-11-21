/*
 * @lc app=leetcode.cn id=491 lang=cpp
 * @lcpr version=20003
 *
 * [491] 非递减子序列
 *
 * https://leetcode.cn/problems/non-decreasing-subsequences/description/
 *
 * algorithms
 * Medium (52.19%)
 * Likes:    827
 * Dislikes: 0
 * Total Accepted:    206.3K
 * Total Submissions: 395.2K
 * Testcase Example:  '[4,6,7,7]'
 *
 * 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序
 * 返回答案。
 *
 * 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [4,6,7,7]
 * 输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [4,4,3,2,1]
 * 输出：[[4,4]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 15
 * -100 <= nums[i] <= 100
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
private:
    vector<vector<int>> result;
    vector<int> path;
    void backTrack(vector<int> &&nums, int start) {
        unordered_set<int> used;
        if (path.size() > 1) {
            result.emplace_back(path);
        }
        for (int i = start; i < nums.size(); i++) {
            if (!path.empty() && nums[i] < path.back() || used.find(nums[i]) != used.end()) {
                continue;
            }
            path.emplace_back(nums[i]);
            used.insert(nums[i]);
            backTrack(std::move(nums), i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        backTrack(std::move(nums), 0);
        return result;
    }

};
// @lc code=end


/*
// @lcpr case=start
// [4,6,7,7]\n
// @lcpr case=end

// @lcpr case=start
// [4,4,3,2,1]\n
// @lcpr case=end

 */
