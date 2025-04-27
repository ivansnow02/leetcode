# 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：n = 3
# 输出：["((()))","(()())","(())()","()(())","()()()"]
#  
# 
#  示例 2： 
# 
#  
# 输入：n = 1
# 输出：["()"]
#  
# 
#  
# 
#  提示： 
# 
#  
#  1 <= n <= 8 
#  
# 
#  Related Topics字符串 | 动态规划 | 回溯 
# 
#  👍 3831, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
# 
# 
# 
#
from typing import List


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def __init__(self):
        self.str = ''
        self.ans: List = []
    def backTrace(self, n1, n2):
        if n1 == 0 and n2 == 0:
            self.ans.append(self.str)
        if n1 > 0:
            self.str += '('
            self.backTrace(n1 - 1, n2)
            self.str = self.str[:-1]
        if n2 > 0:
            if n2 <= n1: return
            self.str += ')'
            self.backTrace(n1, n2 - 1)
            self.str = self.str[:-1]
    def generateParenthesis(self, n: int) -> List[str]:
        self.backTrace(n, n)
        return self.ans
# leetcode submit region end(Prohibit modification and deletion)
