package main
/*
 * @lc app=leetcode.cn id=69 lang=golang
 *
 * [69] x 的平方根 
 *
 * https://leetcode.cn/problems/sqrtx/description/
 *
 * algorithms
 * Easy (38.50%)
 * Likes:    1530
 * Dislikes: 0
 * Total Accepted:    882.9K
 * Total Submissions: 2.3M
 * Testcase Example:  '4'
 *
 * 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
 * 
 * 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
 * 
 * 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 4
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = 8
 * 输出：2
 * 解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= x <= 2^31 - 1
 * 
 * 
 */
import "fmt"
// @lc code=start
import "math"
func mySqrt(x int) int {


	// if x == 0 {
	// 	return 0
	// }
	// var left, right = 1, x
	// for left < right {
	// 	mid := (left + right + 1) >> 1
	// 	if mid * mid > x {
	// 		right = mid - 1
	// 	}else {
	// 		left = mid
	// 	}
	// }
	// return left
	r := fastInvSqrt(float64(x))
	// turn the inverse square root to square root
	r = 1 / r
	return int(r)
	


}
//Fast inverse square root
func fastInvSqrt(x float64) float64 {
	xhalf := 0.5 * x
	i := math.Float64bits(x)
	i =  0x5FE6EC85E7DE30DA - (i >> 1)
	x = math.Float64frombits(i)
	x = x * (1.5 - xhalf*x*x)
	x = x * (1.5 - xhalf*x*x)
	x = x * (1.5 - xhalf*x*x)
	return x
}
// @lc code=end

func main() {
	fmt.Println(fastInvSqrt(4))
}