class Solution {
public:
    
     
    //Approach 3 (Dynamic Programming)
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        for(int i = 0; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int i = 1; i<=amount; i++){
            dp[0][i] = INT_MAX-1;
        }
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=amount; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                }else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][amount]==INT_MAX-1?-1:dp[n][amount];
    }
    
    
    
    //Approach 2 (Memoization)
//     int solve(vector<int> &coins, int amt, int i, vector<vector<int>> &dp){
//         if(amt == 0)
//             return dp[i][amt] = 0;
//         if(i == coins.size())
//             return dp[i][amt] = INT_MAX-1;
//         if(dp[i][amt] != -1)
//             return dp[i][amt];
        
//         int nt = solve(coins, amt, i+1, dp);
//         int t = INT_MAX;
        
//         if(amt >= coins[i]){
//             t = 1+solve(coins, amt-coins[i], i, dp);
//         }
//         return dp[i][amt] = min(t, nt);
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
//         long long x = solve(coins, amount, 0, dp);
//         if(x == INT_MAX || x == INT_MAX-1)
//             return -1;
//         else return x;
//     }
    
    
    //Appproach 1 (Recursion)
    
    // int solve(vector<int> &coins, int amt, int i, int ans){
    //     if(amt == 0)
    //         return ans;
    //     if(i == coins.size())
    //         return -1;
    //     if(amt >= coins[i]){
    //         int a = solve(coins, amt, i+1, ans);
    //         int b = solve(coins, amt-coins[i], i, ans+1);
    //         if(a == -1)
    //             return b;
    //         else if(b == -1)
    //             return a;
    //         else
    //             return min(a, b);
    //     }
    //     else
    //         return solve(coins, amt, i+1, ans);
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     return solve(coins, amount, 0, 0);
    // }
};