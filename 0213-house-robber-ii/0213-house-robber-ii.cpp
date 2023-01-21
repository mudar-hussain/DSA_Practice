class Solution {
public:
    int dp[101];
    int solve(vector<int> &nums, int idx, int &n){
        if(idx>=n)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        
        return dp[idx] = max(solve(nums, idx+1, n), solve(nums, idx+2, n)+nums[idx]);
    }
    int help(vector<int>& nums, int i, int n) {
        
        memset(dp, -1, sizeof(dp));
        return solve(nums, i, n);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        else if(n == 2)
            return max(nums[0], nums[1]);
        else if(n == 3)
            return max({nums[0],nums[1], nums[2]});
        
        return max(help(nums, 0, n-1), help(nums, 1, n));
        
    }
};