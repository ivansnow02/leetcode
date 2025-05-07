from typing import List


# 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
# 
#  单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
# 
#  
# 
#  示例 1： 
#  
#  
# 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
# "ABCCED"
# 输出：true
#  
# 
#  示例 2： 
#  
#  
# 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
# "SEE"
# 输出：true
#  
# 
#  示例 3： 
#  
#  
# 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
# "ABCB"
# 输出：false
#  
# 
#  
# 
#  提示： 
# 
#  
#  m == board.length 
#  n = board[i].length 
#  1 <= m, n <= 6 
#  1 <= word.length <= 15 
#  board 和 word 仅由大小写英文字母组成 
#  
# 
#  
# 
#  进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？ 
# 
#  Related Topics深度优先搜索 | 数组 | 字符串 | 回溯 | 矩阵 
# 
#  👍 1993, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
# 
# 
# 
# 

# leetcode submit region begin(Prohibit modification and deletion)
class Solution:

    def exist(self, board: List[List[str]], word: str) -> bool:
        dirs = [
            [-1, 0],
            [1, 0],
            [0, -1],
            [0, 1],
        ]
        m = len(board)
        n = len(board[0])
        vis = [[False] * n for _ in range(m)]

        flag = False

        def back_trace(x: int, y: int, d: int):
            if d == len(word) - 1:
                nonlocal flag
                flag = True
                return
            vis[x][y] = True
            for dx, dy in dirs:
                xx = x + dx
                yy = y + dy
                if 0 > xx or m <= xx or 0 > yy or n <= yy:
                    continue
                if board[xx][yy] != word[d + 1] or vis[xx][yy]:
                    continue

                back_trace(xx, yy, d + 1)
            vis[x][y] = False

        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]:
                    vis = [[False] * n for _ in range(m)]
                    back_trace(i, j, 0)

        return flag

# leetcode submit region end(Prohibit modification and deletion)
