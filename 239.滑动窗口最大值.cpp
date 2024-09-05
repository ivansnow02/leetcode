#include "MyHeaders.hpp"
using namespace std;
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode.cn/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (49.05%)
 * Likes:    2862
 * Dislikes: 0
 * Total Accepted:    674.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组
 * nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的
 * k 个数字。滑动窗口每次只向右移动一位。
 *
 * 返回 滑动窗口中的最大值 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1], k = 1
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 *
 *
 */

// @lc code=start
template <typename E> class MonotonicQueue {
private:
  deque<E> maxq;

public:
  void push(E e) {
    while (!maxq.empty() && maxq.back() < e) {
      maxq.pop_back();
    }
    maxq.emplace_back(e);
  }
  void pop(E e) {
    if (!maxq.empty() && maxq.front() == e) {
      maxq.pop_front();
    }
  }
  E max() { return maxq.front(); }
};

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    MonotonicQueue<int> mq;
    vector<int> ans;
    for (auto i = 0; i < nums.size(); ++i) {
      if (i < k - 1) {
        mq.push(nums[i]);
      } else {
        mq.push(nums[i]);
        ans.push_back(mq.max());
        mq.pop(nums[i - k + 1]);
      }
    }
    return ans;
  }
};
// @lc code=end
