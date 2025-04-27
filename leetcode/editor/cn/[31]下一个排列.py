from typing import List


# 整数数组的一个 排列 就是将其所有成员以序列或线性顺序排列。
# 
#  
#  例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。 
#  
# 
#  整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就
# 是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。 
# 
#  
#  例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。 
#  类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。 
#  而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。 
#  
# 
#  给你一个整数数组 nums ，找出 nums 的下一个排列。 
# 
#  必须 原地 修改，只允许使用额外常数空间。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：nums = [1,2,3]
# 输出：[1,3,2]
#  
# 
#  示例 2： 
# 
#  
# 输入：nums = [3,2,1]
# 输出：[1,2,3]
#  
# 
#  示例 3： 
# 
#  
# 输入：nums = [1,1,5]
# 输出：[1,5,1]
#  
# 
#  
# 
#  提示： 
# 
#  
#  1 <= nums.length <= 100 
#  0 <= nums[i] <= 100 
#  
# 
#  Related Topics数组 | 双指针 
# 
#  👍 2686, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
# 
# 
# 
# 

# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) <= 1: return
        #  从后向前 查找第一个 相邻升序 的元素对 (i,j)，满足 A[i] < A[j]。此时 [j,end) 必然是降序
        i, j, k = len(nums) - 2, len(nums) - 1, len(nums) - 1
        while i >= 0 and nums[i] >= nums[j]:
            i -= 1
            j -= 1

        #  在 [j,end) 从后向前 查找第一个满足 A[i] < A[k] 的 k。A[i]、A[k] 分别就是上文所说的「小数」、「大数」
        if i >= 0:
            while nums[i] >= nums[k]:
                k -= 1
            nums[i], nums[k] = nums[k], nums[i]

        # 将 A[i] 与 A[k] 交换
        # print(nums)
        # 可以断定这时 [j,end) 必然是降序，逆置 [j,end)，使其升序
        nums[j:] = nums[j:][::-1]
        # print(nums)
        # 如果在步骤 1 找不到符合的相邻元素对，说明当前 [begin,end) 为一个降序顺序，则直接跳到步骤 4
# leetcode submit region end(Prohibit modification and deletion)
