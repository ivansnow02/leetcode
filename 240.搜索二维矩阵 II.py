#
# @lc app=leetcode.cn id=240 lang=python3
# @lcpr version=30201
#
# [240] 搜索二维矩阵 II
#
# https://leetcode.cn/problems/search-a-2d-matrix-ii/description/
#
# algorithms
# Medium (55.55%)
# Likes:    1659
# Dislikes: 0
# Total Accepted:    622.3K
# Total Submissions: 1.1M
# Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n' + '5'
#
# 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
#
#
# 每行的元素从左到右升序排列。
# 每列的元素从上到下升序排列。
#
#
#
#
# 示例 1：
#
# 输入：matrix =
# [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
# target = 5
# 输出：true
#
#
# 示例 2：
#
# 输入：matrix =
# [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
# target = 20
# 输出：false
#
#
#
#
# 提示：
#
#
# m == matrix.length
# n == matrix[i].length
# 1 <= n, m <= 300
# -10^9 <= matrix[i][j] <= 10^9
# 每行的所有元素从左到右升序排列
# 每列的所有元素从上到下升序排列
# -10^9 <= target <= 10^9
#
#
#

# @lc code=start
from typing import List

# def bi_search(nums: List[int], target:int)->bool:
#   l, r = 0, len(nums) - 1
#   while l <= r:
#     # [l.   , mid-1]
#     # [mid+1, r]
#     mid = (l + r) >> 1
#     if target == nums[mid]:
#       return True
#     elif target < nums[mid]:
#       r = mid - 1
#     else:
#       l = mid + 1
#   return False

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
      # min_elem = matrix[0][0]
      # max_elem = matrix[-1][-1]
      # if target < min_elem or target > max_elem:
      #   return False



      # for i, l in enumerate(matrix):
      #   if l[0] <= target <= l[-1]:
      #     if bi_search(l, target):
      #       return True
      # return False
      m = len(matrix)
      n = len(matrix[0])

      x, y = 0, n - 1

      while x < m and y >= 0:
        if matrix[x][y] == target:
          return True
        elif matrix[x][y] > target:
          y -= 1
        else:
          x += 1
      return False




# @lc code=end



#
# @lcpr case=start
# [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5\n
# @lcpr case=end

# @lcpr case=start
# [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n20\n
# @lcpr case=end

#
