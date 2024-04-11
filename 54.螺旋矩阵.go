package main

// import "fmt"

/*
 * @lc app=leetcode.cn id=54 lang=golang
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (50.58%)
 * Likes:    1658
 * Dislikes: 0
 * Total Accepted:    502.2K
 * Total Submissions: 991.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1
 * -100
 *
 *
 */

// @lc code=start
func spiralOrder(matrix [][]int) []int {
	if len(matrix) == 0 {
		return []int{}
	}
	m := len(matrix)
	n := len(matrix[0])
	upperBound, lowerBound := 0, m-1
	leftBound, rightBound := 0, n-1
	ans := make([]int, 0, m*n)
	for len(ans) < m*n {
		if upperBound <= lowerBound {
			for j := leftBound; j <= rightBound; j++ {
				ans = append(ans, matrix[upperBound][j])
			}
			upperBound++
		}
		if leftBound <= rightBound {
			for i := upperBound; i <= lowerBound; i++ {
				ans = append(ans, matrix[i][rightBound])
			}
			rightBound--
		}
		if upperBound <= lowerBound {
			for j := rightBound; j >= leftBound; j-- {
				ans = append(ans, matrix[lowerBound][j])
			}
			lowerBound--
		}
		if leftBound <= rightBound {
			for i := lowerBound; i >= upperBound; i-- {
				ans = append(ans, matrix[i][leftBound])
			}
			leftBound++
		}
	}
	return ans 
}

// @lc code=end

// func main() {
// 	m := [][]int{{1,2,3,4},{5,6,7,8},{9,10,11,12}}
// 	a := spiralOrder(m)
// 	fmt.Println(a)
// }
