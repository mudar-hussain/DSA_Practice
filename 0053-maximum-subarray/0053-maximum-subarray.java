class Solution {
    public int maxSubArray(int[] nums) {
        int maxiSum = Integer.MIN_VALUE, currSum = 0;
        for(int i = 0; i<nums.length; i++){
            currSum = currSum+nums[i];
            maxiSum = Math.max(maxiSum, currSum);
            currSum = Math.max(currSum, 0);
        }
        return maxiSum;
    }
}