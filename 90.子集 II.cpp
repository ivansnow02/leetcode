/*
 * @lc app=leetcode.cn id=90 lang=cpp
 * @lcpr version=20003
 *
 * [90] 子集 II
 *
 * https://leetcode.cn/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (63.54%)
 * Likes:    1249
 * Dislikes: 0
 * Total Accepted:    405.1K
 * Total Submissions: 637.5K
 * Testcase Example:  '[1,2,2]'
 *
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 子集（幂集）。
 *
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,2]
 * 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
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
 *
 *
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
        result.emplace_back(path);
        if (start >= nums.size()) {
            return;
        }
        for (int i = start; i < nums.size(); i++) {

            path.emplace_back(nums[i]);
            if (used.find(nums[i]) == used.end()) {
                used.insert(nums[i]);
                backTrack(std::move(nums), i + 1);
            }
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        backTrack(std::move(nums), 0);
        return result;
    }

};
// @lc code=end


/*
// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
