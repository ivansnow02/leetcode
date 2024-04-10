package main

/*
 * @lc app=leetcode.cn id=76 lang=golang
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (45.61%)
 * Likes:    2877
 * Dislikes: 0
 * Total Accepted:    551K
 * Total Submissions: 1.2M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
 * 。
 *
 *
 *
 * 注意：
 *
 *
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 *
 *
 *
 * 提示：
 *
 *
 * ^m == s.length
 * ^n == t.length
 * 1 <= m, n <= 10^5
 * s 和 t 由英文字母组成
 *
 *
 *
 * 进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？
 */

// @lc code=start
import "math"

func minWindow(s string, t string) string {
	// Create maps to store the count of characters needed and found
	need, window := make(map[rune]int), make(map[rune]int)

	// Initialize the need map with the count of characters in t
	for _, rn := range t {
		need[rn]++
	}

	// Initialize variables for left and right pointers, valid count, start index, and minimum length
	l, r := 0, 0
	valid := 0
	start, length := 0, math.MaxInt32

	// Move the right pointer to expand the window
	for r < len(s) {
		// Get the current character
		x := rune(s[r])
		r++

		// If the character is needed, update the window and valid count
		if _, ok := need[x]; ok {
			window[x]++
			if window[x] == need[x] {
				valid++
			}
		}

		// Move the left pointer to shrink the window
		for valid == len(need) {
			// Update the start index and minimum length if a smaller window is found
			if length > r-l {
				start = l
				length = r - l
			}

			// Get the character at the left pointer
			temp := rune(s[l])
			l++

			// If the character is needed, update the window and valid count
			if _, ok := need[temp]; ok {
				if window[temp] == need[temp] {
					valid--
				}
				window[temp]--
			}
		}
	}

	// If no valid window is found, return an empty string
	if length == math.MaxInt32 {
		return ""
	}

	// Return the minimum window substring
	return s[start : start+length]
}

// @lc code=end
