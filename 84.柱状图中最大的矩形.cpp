/*
 * @lc app=leetcode.cn id=84 lang=cpp
 * @lcpr version=30104
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (47.26%)
 * Likes:    2915
 * Dislikes: 0
 * Total Accepted:    518.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 *
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入： heights = [2,4]
 * 输出： 4
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= heights.length <=10^5
 * 0 <= heights[i] <= 10^4
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        auto ans = 0;
        st.emplace(0);
        heights.insert(heights.begin(), 0);
        heights.insert(heights.end(), 0);
        for (int i = 1; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                auto t = st.top();
                st.pop();
                if (st.empty())
                    continue;
                auto w = i - st.top() - 1;
                ans = max(ans, w * heights[t]);
            }
            st.emplace(i);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

 */
