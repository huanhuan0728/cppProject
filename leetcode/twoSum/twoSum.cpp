#include <iostream>
#include <vector>
#include <unordered_map>

/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。
 */

// 自解
class Solution2
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }

        return {};
    }
};

/* ai解
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // 创建一个哈希表来存储数组元素及其对应的下标
        std::unordered_map<int, int> num_map;

        // 遍历数组
        for (int i = 0; i < nums.size(); ++i) {
            // 计算目标值与当前元素的差值
            int complement = target - nums[i];

            // 检查哈希表中是否存在这个差值
            if (num_map.find(complement) != num_map.end()) {
                // 如果存在，返回差值的下标和当前元素的下标
                return {num_map[complement], i};
            }

            // 如果不存在，将当前元素及其下标存入哈希表
            num_map[nums[i]] = i;
        }

        // 如果没有找到符合条件的两个数，返回空数组
        return {};
    }
};
*/

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end())
            {
                return {num_map[complement], i};
            }

            num_map[nums[i]] = i;
        }

        return {};
    }
};

int main()
{
    // 测试用例 1
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    Solution solution;
    std::vector<int> result1 = solution.twoSum(nums1, target1);
    std::cout << "Test Case 1: ";
    for (int idx : result1)
    {
        std::cout << idx << " ";
    }
    std::cout << std::endl;

    // 测试用例 2
    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = solution.twoSum(nums2, target2);
    std::cout << "Test Case 2: ";
    for (int idx : result2)
    {
        std::cout << idx << " ";
    }
    std::cout << std::endl;

    // 测试用例 3
    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = solution.twoSum(nums3, target3);
    std::cout << "Test Case 3: ";
    for (int idx : result3)
    {
        std::cout << idx << " ";
    }
    std::cout << std::endl;

    // 测试用例 4
    std::vector<int> num4 = {1, 2, 3, 4, 5};
    int target4 = 8;
    std::vector<int> result4 = solution.twoSum(num4, target4);
    std::cout << "Test Case 4: ";
    for (int idx : result4)
    {
        std::cout << idx << " ";
    }
    std::cout << std::endl;

    return 0;
}