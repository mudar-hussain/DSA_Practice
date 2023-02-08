class Solution {
    int dp[10001];
    
    int solve(vector<int>& nums, int idx){
        if(idx>=nums.size()-1)
            return 0;
        if(nums[idx] == 0)
            return INT_MAX;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int mini = INT_MAX-1;
        for(int i = 1; i<=nums[idx]; i++){
            mini = min(mini, solve(nums, idx+i));
        }
        return dp[idx] = 1+mini;
    }
    
public:
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};