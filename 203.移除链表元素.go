package main

/*
 * @lc app=leetcode.cn id=203 lang=golang
 *
 * [203] 移除链表元素
 *
 * https://leetcode.cn/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (56.41%)
 * Likes:    1413
 * Dislikes: 0
 * Total Accepted:    715.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,6,3,4,5,6], val = 6
 * 输出：[1,2,3,4,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [], val = 1
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = [7,7,7,7], val = 7
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 列表中的节点数目在范围 [0, 10^4] 内
 * 1
 * 0
 *
 *
 */
// type ListNode struct {
// 	Val  int
// 	Next *ListNode
// }

// @lc code=start

func removeElements(head *ListNode, val int) *ListNode {
	dummyHead := &ListNode{Next: head}
	
	for i := dummyHead; i.Next != nil; {
		if i.Next.Val == val {
			i.Next = i.Next.Next
		} else {
			i = i.Next
		}
	}
	return dummyHead.Next
}


// @lc code=end
