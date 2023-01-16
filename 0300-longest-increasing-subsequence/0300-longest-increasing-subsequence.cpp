class Solution {
public:
    int solve(vector<int> &nums, int i, int prev_i,  vector<int> &dp){
        if(i >= nums.size())
            return 0;
        
        if(dp[prev_i+1] != -1)
            return dp[prev_i+1];
        int notPick = solve(nums, i+1, prev_i, dp);
        int pick = (prev_i == -1 || nums[i]>nums[prev_i])? 1+solve(nums, i+1, i, dp) : 0;
        
        
        return dp[prev_i+1] = max(pick, notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return solve(nums, 0, -1, dp);
    }
};