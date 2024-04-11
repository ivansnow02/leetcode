package main

/*
 * @lc app=leetcode.cn id=59 lang=golang
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode.cn/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (71.09%)
 * Likes:    1272
 * Dislikes: 0
 * Total Accepted:    414.6K
 * Total Submissions: 583.7K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 *
 *
 */

// @lc code=start
func generateMatrix(n int) [][]int {

	upperBound, lowerBound := 0, n-1
	leftBound, rightBound := 0, n-1
	matrix := make([][]int, n)
	for i := range matrix {
		matrix[i] = make([]int, n)
	}

	cnt := 1
	for cnt <= n*n {
		if upperBound <= lowerBound {
			for j := leftBound; j <= rightBound; j++ {
				matrix[upperBound][j] = cnt
				cnt++
			}
			upperBound++
		}
		if leftBound <= rightBound {
			for i := upperBound; i <= lowerBound; i++ {
				matrix[i][rightBound] = cnt
				cnt++
			}
			rightBound--
		}
		if upperBound <= lowerBound {
			for j := rightBound; j >= leftBound; j-- {
				matrix[lowerBound][j] = cnt
				cnt++
			}
			lowerBound--
		}
		if leftBound <= rightBound {
			for i := lowerBound; i >= upperBound; i-- {
				matrix[i][leftBound] = cnt
				cnt++
			}
			leftBound++
		}
	}
	return matrix
}

// @lc code=end
