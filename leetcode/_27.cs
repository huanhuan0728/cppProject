public class Solution
{
    public int RemoveElement(int[] nums. int val)
    {
        int left = 0;
        int right = nums.Length - 1;
        while (left <= right)
        {
            while (left <= right && nums[left] != val)
            {
                left++;
            }
            while (left <= right && nums[right] == val)
            {
                right--;
            }
            if (left < right)
            {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
        }

        return left;
    }
}