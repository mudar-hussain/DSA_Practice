class Solution {
public:
    int solve(vector<int> &nums, int i, int j, int n, vector<vector<int>> &dp){
        
         if(i>j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int mx = INT_MIN;
        
        for(int k = i; k<=j; k++){
            int t = (i>0 ? nums[i-1]:1) * nums[k] * (j+1<n? nums[j+1]:1);
            int temp  = solve(nums, i, k-1, n, dp) + solve(nums, k+1, j, n, dp) + t;
            mx = max(mx, temp);
        }
        return dp[i][j] = mx;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(nums, 0, n-1, n, dp);
        
    }
};