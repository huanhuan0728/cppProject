from typing import List

class Solution:
    def removeElement(self, nums: List[int], val:int):
        left = 0
        right = len(nums) - 1
        while left <= right:
            while left <= right and nums[left] != val:
                left += 1
            while left <= right and nums[right] == val:
                right -= 1
            if left < right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1
        return left

nums = [3, 2, 2, 3]
val = 3
solution = Solution()
new_length = solution.removeElement(nums, val)
print("New length:", new_length)
print("Modified array:", nums[:new_length])