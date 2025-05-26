#
# @lc app=leetcode.cn id=148 lang=python3
# @lcpr version=30201
#
# [148] 排序链表
#
# https://leetcode.cn/problems/sort-list/description/
#
# algorithms
# Medium (67.25%)
# Likes:    2525
# Dislikes: 0
# Total Accepted:    696.2K
# Total Submissions: 1M
# Testcase Example:  '[4,2,1,3]'
#
# 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
#
#
#
#
#
#
# 示例 1：
#
# 输入：head = [4,2,1,3]
# 输出：[1,2,3,4]
#
#
# 示例 2：
#
# 输入：head = [-1,5,3,4,0]
# 输出：[-1,0,3,4,5]
#
#
# 示例 3：
#
# 输入：head = []
# 输出：[]
#
#
#
#
# 提示：
#
#
# 链表中节点的数目在范围 [0, 5 * 10^4] 内
# -10^5 <= Node.val <= 10^5
#
#
#
#
# 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
#
#
# Definition for singly-linked list.
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# @lc code=start
def sortList(head: ListNode) -> ListNode:
    if not head or not head.next:
        return head

    mid = findMiddleAndSplit(head)

    left = sortList(head)
    right = sortList(mid)

    return merge(left, right)

def findMiddleAndSplit(head: ListNode) -> ListNode:
    slow = fast = head
    prev = None

    while fast and fast.next:
        prev = slow
        slow = slow.next
        fast = fast.next.next

    # 断开链表
    if prev:
        prev.next = None

    return slow

def merge(l1: ListNode, l2: ListNode) -> ListNode:
    dummy = ListNode(0)
    curr = dummy

    while l1 and l2:
        if l1.val <= l2.val:
            curr.next = l1
            l1 = l1.next
        else:
            curr.next = l2
            l2 = l2.next
        curr = curr.next

    curr.next = l1 or l2
    return dummy.next


class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        return sortList(head)

# @lc code=end



#
# @lcpr case=start
# [4,2,1,3]\n
# @lcpr case=end

# @lcpr case=start
# [-1,5,3,4,0]\n
# @lcpr case=end

# @lcpr case=start
# []\n
# @lcpr case=end

#
