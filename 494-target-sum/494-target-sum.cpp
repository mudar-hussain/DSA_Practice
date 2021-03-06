class Solution {
public:
    //3rd Approach (Knapsack)
     int findTargetSumWays(vector<int>& nums, int target) {
         int n = nums.size();
         int sum = 0;
         for(int i: nums)
             sum += i;
         
         if(sum<target ||(sum+target)/2<0 || (sum+target)%2 != 0)
             return 0;
         
         sum = (sum+target)/2;
         int dp[n+1][sum+1];
         for(int i = 0; i<=sum; i++)
             dp[0][i] = 0;
         for(int i = 0; i<=n; i++)
             dp[i][0] = 1;
         
         for(int i = 1; i<=n; i++){
             for(int j = 0; j<=sum; j++){
                 if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
             }
         }
         return dp[n][sum];
         
     }
    
    //2nd Approach (Knapsack)
    
//     int countSubsets(vector<int>& nums, int target) {
//         int n = nums.size();
//         int dp[n+1][target+1];
//         dp[0][0] = 1;
//         for(int i = 0; i<=n; i++){
//             for(int j = 0; j<=target; j++){
//                 if(i == 0 && j == 0)
//                     continue;
//                 if(i == 0 && j != 0){
//                     dp[i][j] = 0;
//                 }
//                 else
//                 {
//                     if(nums[i-1] <= j)
//                         dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
//                     else
//                         dp[i][j] = dp[i-1][j];
//                 }
//             }
//         }
//         return dp[n][target];
//     }
    
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int sum = 0;
//         for(int i: nums)
//             sum += i;
//         if(abs(target) > sum || (sum+target)%2 != 0)
//             return 0;
//         sum = (sum+target)/2;
//         return countSubsets(nums, sum);
//     }
                               
                               
    //1st Approach (Recursion)
//     void knapsack(vector<int> &nums, int n, int target, int &ans){
//         if(n == -1 && target == 0){
//             ans++;
//             return;
//         }else if(n == -1){
//             return;
//         }
//         knapsack(nums, n-1, target-nums[n], ans);
//         knapsack(nums, n-1, target+nums[n], ans);
//     }
    
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int ans = 0;
//         knapsack(nums, n-1, target, ans);
//         return ans;
//     }
};