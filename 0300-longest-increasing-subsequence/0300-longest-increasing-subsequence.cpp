class Solution {
public:
    
    int dp[2502][2502];
    int solve(vector<int>& nums, int pi, int i){
        if(i >= nums.size())
            return 0;
        
        if(dp[i][pi+1] != -1)
            return dp[i][pi+1];
        
        int len = solve(nums, pi, i+1);
        
        if(pi == -1 || nums[i] > nums[pi])
            len = max(len, 1+solve(nums, i, i+1));
        
        return dp[i][pi+1] = len;
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, -1, 0);
        
    }
};