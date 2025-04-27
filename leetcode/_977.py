def solution977(nums):
    n = len(nums)
    left, right = 0, n-1
    k = n-1
    result = [0] * n
    while left <= right:
        if nums[left]**2 < nums[right]**2:
            result[k] = nums[right]**2
            k -= 1
            right -= 1
        else:
            result[k] = nums[left]**2
            k -= 1
            left += 1
    
    return result