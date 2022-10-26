class Solution {
public:
    int dp[10001];
    int solve(vector<int> &nums, int idx){
        if(idx == nums.size()-1)
            return 1;
        if(idx >= nums.size())
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        for(int i = nums[idx]; i>0; i--){
            if(idx + i < nums.size())
                if(solve(nums, idx+i))
                    return dp[idx] = 1;
        }
        return dp[idx] = 0;
    }
    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
    
        return solve(nums, 0);
        
        
        
        
    }
};