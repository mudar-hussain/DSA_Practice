class Solution {
public:
    int solve(vector<int> &nums, int i, int prev_i,  vector<vector<int>> &dp){
        if(i >= nums.size())
            return 0;
        
        if(dp[i][prev_i+1] != -1)
            return dp[i][prev_i+1];
        int notPick = solve(nums, i+1, prev_i, dp);
        int pick = (prev_i == -1 || nums[i]>nums[prev_i])? 1+solve(nums, i+1, i, dp) : 0;
        
        
        return dp[i][prev_i+1] = max(pick, notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return solve(nums, 0, -1, dp);
    }
};