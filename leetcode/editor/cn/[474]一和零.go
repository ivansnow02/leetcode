package main


// leetcode submit region begin(Prohibit modification and deletion)
import "strings"
func findMaxForm(strs []string, m int, n int) int {
	dp := make([][]int, m+1)
	for i, _ := range dp {
		dp[i] = make([]int, n+1)
	}
	for _, s := range strs {
		zero := strings.Count(s, "0")
		one := strings.Count(s, "1")
		for x := m; x >= zero; x-- {
			for y := n; y >= one; y-- {
				dp[x][y] = max(dp[x][y], dp[x-zero][y-one]+1)
			}
		}
	}
	return dp[m][n]
}

//leetcode submit region end(Prohibit modification and deletion)
