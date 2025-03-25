// 错解
// class Solution {
//     public:
//         int removeElement(vector<int>& nums, int val) {
//             int n = nums.size();
//             int left = 0;
//             int right = n-1;
//             while(left <= right)
//             {
//                 while(nums[left] != val && left < right)
//                 {
//                     left++;
//                 }

//                 while(nums[right] == val && right > left)
//                 {
//                     right--;
//                 }

//                 if(left >= right)
//                     break;

//                 swap(nums[left], nums[right]);
//             }

//             return right+1;
//         }
//     };

#include <vector>
class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            // 防止左指针越界：添加 left <= right 边界检查[3,5](@ref)
            while (left <= right && nums[left] != val)
            {
                ++left;
            }

            // 防止右指针越界：添加 right >= left 边界检查[1,6](@ref)
            while (left <= right && nums[right] == val)
            {
                --right;
            }

            if (left < right)
            {
                std::swap(nums[left], nums[right]);
                ++left;
                --right;
            }
        }
        return left;
    }
};