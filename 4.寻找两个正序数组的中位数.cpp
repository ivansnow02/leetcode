/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=30104
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (43.40%)
 * Likes:    7503
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 *
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 *
 * 示例 2：
 *
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 *
 */
#include <algorithm>
#include <limits>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
// @lc code=start
class Solution {
// private:
//     double mergeTwoArrays(const vector<int> &nums1, const vector<int> &nums2) {
//         int m = nums1.size(), n = nums2.size(), total = m + n;
//         int mid = total / 2;
//         vector<int> merged;
//         merged.reserve(mid + 1);
//         int i = 0, j = 0;
//         while ((int) merged.size() <= mid) {
//             if (i < m && (j >= n || nums1[i] <= nums2[j])) {
//                 merged.push_back(nums1[i++]);
//             } else {
//                 merged.push_back(nums2[j++]);
//             }
//         }
//         if (total % 2 == 0) {
//             return (merged[mid - 1] + merged[mid]) / 2.0;
//         } else {
//             return merged[mid];
//         }
//     }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int totalLeft = (nums1.size() + nums2.size() + 1) >> 1;
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int l = 0, r = nums1.size();
        while (l < r) {
            auto m = (l + r + 1) >> 1;
            auto n = totalLeft - m;
            if (nums1[m - 1] > nums2[n]) {
                r = m - 1;
            } else {
                l = m;
            }
        }
        auto m = l;
        auto n = totalLeft - m;

        auto l1 = m == 0 ? numeric_limits<int>::min() : nums1[m - 1];
        auto r1 = m == nums1.size() ? numeric_limits<int>::max() : nums1[m];
        auto l2 = n == 0 ? numeric_limits<int>::min() : nums2[n - 1];
        auto r2 = n == nums2.size() ? numeric_limits<int>::max() : nums2[n];
        if ((nums1.size() + nums2.size()) % 2) {
            return max(l1, l2);
        } else {
            return double(min(r1, r2) + max(l1, l2)) / 2;
        }
    }
};
// @lc code=end


/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end
// @lcpr case=start
// [1,2,3,4,5]\n[6,7,8,9,10,11,12,13,14,15,16,17]\n
// @lcpr case=end
 */
