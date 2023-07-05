class Solution {
    int ans = INT_MIN;
    int dp[100001][2];
    int solve(vector<int>& nums, int idx, int count, int canRemove){
        if(idx >= nums.size()){
            if(canRemove && count == nums.size()){
                return count-1;
            }
            return count;
        }
        
        if(dp[idx][canRemove] != -1){
            return dp[idx][canRemove];
        }
        
        
        if(nums[idx] == 1){
            return dp[idx][canRemove] = solve(nums, idx+1, count+1, canRemove);
        }
        
        
        if(canRemove){
            return dp[idx][canRemove] = solve(nums, idx+1, count, 0);
        }
        
        return count;
    }
public:
    int longestSubarray(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                ans = max(ans, solve(nums, i, 0, 1));
            }
        }
        return ans;
    }
};