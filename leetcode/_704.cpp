#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int maxsize = nums.size();
        int left = 0;
        int right = maxsize - 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (target < nums[middle])
            {
                right = middle - 1;
            }
            else if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
};