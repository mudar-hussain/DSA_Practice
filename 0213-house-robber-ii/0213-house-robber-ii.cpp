class Solution {
public:
    int solve(vector<int> & nums, int l, int r){
        int dp[r+1];
        dp[l] = 0;
        dp[l+1] = nums[l];
        for(int i = l+2; i<=r; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        
        return dp[r];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        else if(n == 2)
            return max(nums[0], nums[1]);
        else if(n == 3)
            return max({nums[0],nums[1], nums[2]});
        
        return max(solve(nums, 0, n-1), solve(nums, 1, n));
        
    }
};