public class Solution {
    public int MinSubArrayLen(int target, int[] nums) {
        int result = int.MaxValue;
        int sum = 0;
        int j = 0;
        for (int i = 0; i < nums.Length; i++){
            sum += nums[i];
            while(sum>=target){
                int subLength = i-j+1;
                result = Math.Min(result, subLength);
                sum -= nums[j];
                j++;
            }
        }

        return result == int.MaxValue? 0:result;
    }
}