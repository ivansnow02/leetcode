/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=20003
 *
 * [47] 全排列 II
 *
 * https://leetcode.cn/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (66.06%)
 * Likes:    1631
 * Dislikes: 0
 * Total Accepted:    602.7K
 * Total Submissions: 912.2K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
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
    void backTrack(vector<int> &&nums, vector<bool> &used) {
        if (path.size() == nums.size()) {
            result.emplace_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && used[i - 1] == false && nums[i] == nums[i - 1] || used[i]) {
                continue;
            }
            used[i] = true;
            path.emplace_back(nums[i]);
            backTrack(std::move(nums), used);
            path.pop_back();
            used[i] = false;

        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<bool> used(nums.size());
        sort(nums.begin(), nums.end());
        backTrack(std::move(nums), used);
        return result;
    }
};
// @lc code=end


/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
