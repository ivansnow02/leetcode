# 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
# 
#  
# 
#  示例 1： 
#  
#  
# 输入：l1 = [1,2,4], l2 = [1,3,4]
# 输出：[1,1,2,3,4,4]
#  
# 
#  示例 2： 
# 
#  
# 输入：l1 = [], l2 = []
# 输出：[]
#  
# 
#  示例 3： 
# 
#  
# 输入：l1 = [], l2 = [0]
# 输出：[0]
#  
# 
#  
# 
#  提示： 
# 
#  
#  两个链表的节点数目范围是 [0, 50] 
#  -100 <= Node.val <= 100 
#  l1 和 l2 均按 非递减顺序 排列 
#  
# 
#  Related Topics递归 | 链表 
# 
#  👍 3763, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
# 
# 
# 
# 

# leetcode submit region begin(Prohibit modification and deletion)
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        root = head = ListNode()

        while list1 and list2:
            if list1.val < list2.val:
                head.next, list1 = list1, list1.next
            else:
                head.next, list2 = list2, list2.next
            head = head.next

        head.next = list1 or list2
        return root.next

# leetcode submit region end(Prohibit modification and deletion)
