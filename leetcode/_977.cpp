#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int k = nums.size() - 1;
        vector<int> result(k + 1);
        int i = 0;
        int j = k;
        while (i <= j)
        {
            if (nums[i] * nums[i] <= nums[j] * nums[j])
            {
                result[k--] = nums[j] * nums[j];
                j--;
            }
            else
            {
                result[k--] = nums[i] * nums[i];
                i++;
            }
        }

        return result;
    }
};