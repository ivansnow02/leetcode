package main
/*
 * @lc app=leetcode.cn id=349 lang=golang
 *
 * [349] 两个数组的交集
 *
 * https://leetcode.cn/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (74.53%)
 * Likes:    903
 * Dislikes: 0
 * Total Accepted:    562.5K
 * Total Submissions: 754.6K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组 nums1 和 nums2 ，返回 它们的 交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 解释：[4,9] 也是可通过的
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 * 
 * 
 */

// @lc code=start
func intersection(nums1 []int, nums2 []int) []int {
	m1 := make(map[int]struct{})
	for _, x := range nums1 {
		m1[x] = struct{}{}
	}
	ans := make([]int, 0, min(len(nums1), len(nums2)))
	for _, x := range nums2 {
		if _, ok := m1[x]; ok {
			ans = append(ans, x)
			delete(m1, x)
		}
	}
	return ans
}
// @lc code=end

