#include <vector>
#include <climits>

using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0;
        int n = nums.size();
        int sum = 0;
        int result = INT32_MAX;
        int subLength = 0;
        for (int right = 0; right < n; right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                subLength = right - left + 1;
                result = result < subLength ? result : subLength;
                sum -= nums[left++];
            }
        }

        return result == INT32_MAX ? 0 : result;
    }
};