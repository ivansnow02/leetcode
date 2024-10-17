
//给定一个整数数组
// prices，其中第 prices[i] 表示第 i 天的股票价格 。 
//
// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）: 
//
// 
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。 
// 
//
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
//
// 
//
// 示例 1: 
//
// 
//输入: prices = [1,2,3,0,2]
//输出: 3 
//解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出] 
//
// 示例 2: 
//
// 
//输入: prices = [1]
//输出: 0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= prices.length <= 5000 
// 0 <= prices[i] <= 1000 
// 
//
// Related Topics数组 | 动态规划 
//
// 👍 1774, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//

import java.util.ArrayList;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int maxProfit(int[] prices) {

        int n = prices.length;
        if (n == 0) return 0;

        List<List<Integer>> dp = new ArrayList<>(prices.length);
        for (int i = 0; i < prices.length; i++) {
            dp.add(new ArrayList<>(4));
            for (int j = 0; j < 4; j++) {
                dp.get(i).add(0);
            }
        }
        dp.getFirst().set(0, -prices[0]);

        for (int i = 1; i < n; i++) {
            dp.get(i).set(0, Math.max(dp.get(i - 1).get(0), Math.max(dp.get(i - 1).get(3) - prices[i], dp.get(i - 1).get(1) - prices[i])));
            dp.get(i).set(1, Math.max(dp.get(i - 1).get(1), dp.get(i - 1).get(3)));
            dp.get(i).set(2, dp.get(i - 1).get(0) + prices[i]);
            dp.get(i).set(3, dp.get(i - 1).get(2));
        }

        return Math.max(dp.get(n - 1).get(2), Math.max(dp.get(n - 1).get(3), dp.get(n - 1).get(1)));


    }
}
//leetcode submit region end(Prohibit modification and deletion)
