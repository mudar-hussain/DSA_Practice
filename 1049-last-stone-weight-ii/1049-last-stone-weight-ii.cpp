class Solution {
public:
    int subsetSum(vector<int> &nums, int range){
        int n = nums.size();
        bool dp[n+1][range+1];
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=range; j++){
                if(i == 0 || j == 0){
                    if(i == 0)
                        dp[i][j] = false;
                    if(j == 0)
                        dp[i][j] = true;
                }else{
                    if(nums[i-1] <= j){
                        // cout<<j-nums[i-1]<<" ";
                        dp[i][j] = (dp[i-1][j] || dp[i-1][j-nums[i-1]]);
                    }else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i<=range/2; i++){
            if(dp[n][i] == true)
                ans = min(ans, range-(2*i));
        }
        return ans;
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int i: stones)
            sum += i;
        return subsetSum(stones, sum);
    }
};