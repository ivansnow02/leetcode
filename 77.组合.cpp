/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=20003
 *
 * [77] 组合
 *
 * https://leetcode.cn/problems/combinations/description/
 *
 * algorithms
 * Medium (77.40%)
 * Likes:    1692
 * Dislikes: 0
 * Total Accepted:    794.4K
 * Total Submissions: 1M
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 *
 * 你可以按 任何顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 * 示例 2：
 *
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 20
 * 1 <= k <= n
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
    vector<vector<int>> res;
    vector<int> path;
    bool bound(int n, int k, int i) {
        return i <= n - (k - path.size()) + 1;
    }
    void backTrack(int n, int k, int start) {
        if (path.size() == k) {
            res.emplace_back(path);
        }
        for (int i = start; i <= n; i++) {
            path.emplace_back(i);
            if (bound(n, k, i))
                backTrack(n, k, i + 1);

            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backTrack(n, k, 1);

        return res;
    }
};
// @lc code=end


/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */
