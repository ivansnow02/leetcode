from typing import List


# 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
# 
#  你可以假设数组是非空的，并且给定的数组总是存在多数元素。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：nums = [3,2,3]
# 输出：3 
# 
#  示例 2： 
# 
#  
# 输入：nums = [2,2,1,1,1,2,2]
# 输出：2
#  
# 
#  
# 提示：
# 
#  
#  n == nums.length 
#  1 <= n <= 5 * 10⁴ 
#  -10⁹ <= nums[i] <= 10⁹ 
#  
# 
#  
# 
#  进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。 
# 
#  Related Topics数组 | 哈希表 | 分治 | 计数 | 排序 
# 
#  👍 2478, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
# 
# 
# 
# 

# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # mmap:dict = {}
        # for n in nums:
        #     mmap[n] = mmap.get(n, 0) + 1
        #
        # for k, v in mmap.items():
        #     if v > len(nums)/2:
        #         return k
        # return -1
        cnt = 0
        elem = 0
        for n in nums:
            if cnt == 0:
                elem = n
                cnt += 1
            elif elem == n:
                cnt += 1
            else:
                cnt -= 1
        return elem

# leetcode submit region end(Prohibit modification and deletion)
