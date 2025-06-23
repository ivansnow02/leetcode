
# 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。 
# 
#  
# 
#  示例 1： 
# 
#  
#  输入：root = [1,2,3,null,5,null,4] 
#  
# 
#  输出：[1,3,4] 
# 
#  解释： 
# 
#  
# 
#  示例 2： 
# 
#  
#  输入：root = [1,2,3,4,null,null,null,5] 
#  
# 
#  输出：[1,3,4,5] 
# 
#  解释： 
# 
#  
# 
#  示例 3： 
# 
#  
#  输入：root = [1,null,3] 
#  
# 
#  输出：[1,3] 
# 
#  示例 4： 
# 
#  
#  输入：root = [] 
#  
# 
#  输出：[] 
# 
#  
# 
#  提示: 
# 
#  
#  二叉树的节点个数的范围是 [0,100] 
#  
#  -100 <= Node.val <= 100 
#  
# 
#  Related Topics树 | 深度优先搜索 | 广度优先搜索 | 二叉树 
# 
#  👍 1212, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
# 
# 
# 
# 

# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        
# leetcode submit region end(Prohibit modification and deletion)
