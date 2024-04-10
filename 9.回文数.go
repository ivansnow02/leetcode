/*
 * @lc app=leetcode.cn id=9 lang=golang
 *
 * [9] 回文数
 */
package main

// @lc code=start
func isPalindrome(x int) bool {
	if x < 0 {
		return false
	} else if x < 10 {
		return true
	} else if x%10 == 0 {
		return false
	}
	var y int
	for x > y {
		y = y*10 + x%10
		x /= 10
	}
	return x == y || x == y/10

}

// @lc code=endeeii
