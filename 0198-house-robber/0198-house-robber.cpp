class Solution {
public:
    int dp[101];
    int solve(vector<int> &nums,  int i){
        if(i >=nums.size()){
            return dp[nums.size()] = 0;
        }
        if(dp[i] != -1)
            return dp[i];
        return dp[i] = max(solve(nums,  i+1), solve(nums, i+2)+nums[i]);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
        //return dp[nums.size()];
    }
};