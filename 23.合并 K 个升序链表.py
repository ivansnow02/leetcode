#
# @lc app=leetcode.cn id=23 lang=python3
# @lcpr version=30201
#
# [23] 合并 K 个升序链表
#
# https://leetcode.cn/problems/merge-k-sorted-lists/description/
#
# algorithms
# Hard (62.06%)
# Likes:    3022
# Dislikes: 0
# Total Accepted:    1M
# Total Submissions: 1.6M
# Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
#
# 给你一个链表数组，每个链表都已经按升序排列。
#
# 请你将所有链表合并到一个升序链表中，返回合并后的链表。
#
#
#
# 示例 1：
#
# 输入：lists = [[1,4,5],[1,3,4],[2,6]]
# 输出：[1,1,2,3,4,4,5,6]
# 解释：链表数组如下：
# [
# ⁠ 1->4->5,
# ⁠ 1->3->4,
# ⁠ 2->6
# ]
# 将它们合并到一个有序链表中得到。
# 1->1->2->3->4->4->5->6
#
#
# 示例 2：
#
# 输入：lists = []
# 输出：[]
#
#
# 示例 3：
#
# 输入：lists = [[]]
# 输出：[]
#
#
#
#
# 提示：
#
#
# k == lists.length
# 0 <= k <= 10^4
# 0 <= lists[i].length <= 500
# -10^4 <= lists[i][j] <= 10^4
# lists[i] 按 升序 排列
# lists[i].length 的总和不超过 10^4
#
#
#
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# @lc code=start

from typing import List, Optional

def merge(l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    if not l1:
        return l2
    if not l2:
        return l1

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


def divide_merge(lists: List[Optional[ListNode]]) -> Optional[ListNode]:
    if not lists:
        return None
    if len(lists) == 1:
        return lists[0]

    mid = len(lists) // 2
    left = divide_merge(lists[:mid])
    right = divide_merge(lists[mid:])
    return merge(left, right)


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # ans = ListNode(-10 ** 5)
        # for list in lists:
        #     ans = merge(ans, list)
        # return ans.next

        return divide_merge(lists=lists)


# @lc code=end



#
# @lcpr case=start
# [[1,4,5],[1,3,4],[2,6]]\n
# @lcpr case=end

# @lcpr case=start
# []\n
# @lcpr case=end

# @lcpr case=start
# [[]]\n
# @lcpr case=end

#
