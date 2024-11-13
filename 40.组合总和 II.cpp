/*
 * @lc app=leetcode.cn id=40 lang=cpp
 * @lcpr version=20003
 *
 * [40] 组合总和 II
 *
 * https://leetcode.cn/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (59.65%)
 * Likes:    1597
 * Dislikes: 0
 * Total Accepted:    574.1K
 * Total Submissions: 962.5K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 *
 * 注意：解集不能包含重复的组合。 
 *
 *
 *
 * 示例 1:
 *
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 * 示例 2:
 *
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
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
    vector<int> ans;
    vector<vector<int>> result;
    vector<bool> visited;
    bool bound(int sum, int target) { return sum <= target; }
    bool restrain(const vector<int> &candidates, int i) {
        return !(i > 0 && candidates[i] == candidates[i - 1] && visited[i - 1] == false);
    }
    void backTrack(const vector<int> &candidates, int target, int sum, int start) {
        if (sum == target) {
            result.emplace_back(ans);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            ans.emplace_back(candidates[i]);
            sum += candidates[i];
            visited[i] = true;
            if (bound(sum, target) && restrain(candidates, i)) {
                backTrack(candidates, target, sum, i + 1); // i must +1
            }
            visited[i] = false;
            sum -= candidates[i];
            ans.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        visited.resize(candidates.size());
        ranges::sort(candidates);
        backTrack(candidates, target, 0, 0);
        return result;
    }
};
// @lc code=end


/*
// @lcpr case=start
// [10,1,2,7,6,1,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5\n
// @lcpr case=end

 */
