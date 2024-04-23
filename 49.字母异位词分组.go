package main

/*
 * @lc app=leetcode.cn id=49 lang=golang
 *
 * [49] 字母异位词分组
 *
 * https://leetcode.cn/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (67.95%)
 * Likes:    1876
 * Dislikes: 0
 * Total Accepted:    690.8K
 * Total Submissions: 1M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 *
 * 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * 示例 2:
 *
 *
 * 输入: strs = [""]
 * 输出: [[""]]
 *
 *
 * 示例 3:
 *
 *
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
 *
 *
 */

// @lc code=start
func groupAnagrams(strs []string) [][]string {
	codes := make(map[int][]string)
	for _, s := range strs {
		codes[encode(s)] = append(codes[encode(s)], s)
	}
	res := make([][]string, 0, len(codes))
	for _, s := range codes {
		res = append(res, s)
	}
	return res
}

func encode(s string) int {
	primes := []int{2, 3, 5, 7, 11, 13, 17, 19,
		23, 29, 31, 37, 41, 43, 47, 53,
		59, 61, 67, 71, 73, 79, 83, 89,
		97, 101}
	ans := 1
	for _, b := range s {
		ans *= primes[b-'a']
		ans %= 1e9 + 7
	}
	return ans
}

// @lc code=end
