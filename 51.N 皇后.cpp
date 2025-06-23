/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=30201
 *
 * [51] N 皇后
 *
 * https://leetcode.cn/problems/n-queens/description/
 *
 * algorithms
 * Hard (75.47%)
 * Likes:    2306
 * Dislikes: 0
 * Total Accepted:    546.6K
 * Total Submissions: 724.2K
 * Testcase Example:  '4'
 *
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 *
 *
 *
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 *
 *
 * 示例 2：
 *
 * 输入：n = 1
 * 输出：[["Q"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 9
 *
 *
 *
 *
 */

#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<string> chessboard;
    vector<vector<string>> ans;

    bool check(int x, int y, int n) {
        if (x == 0) {
            return true;
        }
        for (int i = 0; i < x; ++i) {
            if (chessboard[i][y] == 'Q') {
                return false;
            }
        }

        for (int i = x, j = y; i >= 0 && j >= 0; --i, --j) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = x, j = y; i >= 0 && j < n; --i, ++j) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void backTrace(int d, int n) {
        if (d == n) {
            ans.push_back(chessboard);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!check(d, i, n)) {
                continue;
            }
            chessboard[d][i] = 'Q';
            backTrace(d + 1, n);
            chessboard[d][i] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        chessboard = vector<string>(n, string(n, '.'));
        backTrace(0, n);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
