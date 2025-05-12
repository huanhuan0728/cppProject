#include <iostream>
#include <string>
using namespace std;
#include <vector>>
#include <unordered_set>

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // 创建一个结果哈希集合
        unordered_set<int> result_set;
        // 将nums1存放到一个哈希集合里
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        // 如果nums2里有nums1出现过的元素，放到结果集合中
        for (int num : nums2)
        {
            if (nums1_set.find(num) != nums1_set.end())
            {
                result_set.insert(num);
            }
        }

        // 返回将结果哈希集合转化成的数组
        return vector<int>(result_set.begin(), result_set.end());
    }
};