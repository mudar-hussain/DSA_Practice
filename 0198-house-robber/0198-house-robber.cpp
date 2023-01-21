class Solution {
public:
    int dp[101];
    int solve(vector<int> &nums, int idx){
        if(idx>=nums.size())
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        
        return dp[idx] = max(solve(nums, idx+1), solve(nums, idx+2)+nums[idx]);
    }
    int rob(vector<int>& nums) {
        
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};