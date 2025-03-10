/*
 * @lc app=leetcode.cn id=216 lang=cpp
 * @lcpr version=20003
 *
 * [216] 组合总和 III
 *
 * https://leetcode.cn/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (71.45%)
 * Likes:    892
 * Dislikes: 0
 * Total Accepted:    432K
 * Total Submissions: 604.7K
 * Testcase Example:  '3\n7'
 *
 * 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
 *
 *
 * 只使用数字1到9
 * 每个数字 最多使用一次 
 *
 *
 * 返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
 *
 *
 *
 * 示例 1:
 *
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 * 解释:
 * 1 + 2 + 4 = 7
 * 没有其他符合的组合了。
 *
 * 示例 2:
 *
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 * 解释:
 * 1 + 2 + 6 = 9
 * 1 + 3 + 5 = 9
 * 2 + 3 + 4 = 9
 * 没有其他符合的组合了。
 *
 * 示例 3:
 *
 * 输入: k = 4, n = 1
 * 输出: []
 * 解释: 不存在有效的组合。
 * 在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 2 <= k <= 9
 * 1 <= n <= 60
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
    int N, K;
    int sum = 0;
    vector<int> path;
    vector<vector<int>> res;
    bool constraint(int i) { return i <= 10 - (K - path.size()); }
    bool bound(int i) {
        int tsum = sum;
        int x = 9;
        for (auto j = path.size(); j < K; j++) {
            tsum += x--;
        }
        return tsum >= N && sum <= N;
    }
    void backTrack(int start) {
        if (path.size() == K) {
            if (sum == N)
                res.emplace_back(path);
            return;
        }
        for (int i = start; i <= 9; i++) {
            path.emplace_back(i);
            sum += i;
            if (bound(i) && constraint(i)) {
                backTrack(i + 1);
            }
            sum -= i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        this->K = k;
        this->N = n;
        backTrack(1);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n9\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n
// @lcpr case=end

 */
