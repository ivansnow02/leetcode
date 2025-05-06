# 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
# 
#  比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下： 
# 
#  
# P   A   H   N
# A P L S I I G
# Y   I   R 
# 
#  之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。 
# 
#  请你实现这个将字符串进行指定行数变换的函数： 
# 
#  
# string convert(string s, int numRows); 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：s = "PAYPALISHIRING", numRows = 3
# 输出："PAHNAPLSIIGYIR"
#  
# 
# 示例 2：
# 
#  
# 输入：s = "PAYPALISHIRING", numRows = 4
# 输出："PINALSIGYAHRPI"
# 解释：
# P     I    N
# A   L S  I G
# Y A   H R
# P     I
#  
# 
#  示例 3： 
# 
#  
# 输入：s = "A", numRows = 1
# 输出："A"
#  
# 
#  
# 
#  提示： 
# 
#
#  1 <= s.length <= 1000 
#  s 由英文字母（小写和大写）、',' 和 '.' 组成 
#  1 <= numRows <= 1000 
#  
# 
#  Related Topics字符串 
# 
#  👍 2498, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
# 
# 
# 
# 

# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        ss = ["" for _ in range(numRows)]
        j = numRows - 2
        if numRows > len(s):
            return s
        if numRows == 1:
            return s
        for i in range(numRows):
            ss[i] += s[i]
        flag = False
        for i in range(numRows, len(s)):
            ss[j] += s[i]
            if flag is False:
                j -= 1
            else:
                j += 1
            if j == -1 and flag is False:
                j = 1
                flag = True
            elif j == numRows and flag is True:
                j = numRows - 2
                flag = False

        return "".join(ss)

# leetcode submit region end(Prohibit modification and deletion)
