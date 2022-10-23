class Solution {
public:
//     int dp[301][5001];
//     int solve(vector<int> &coins, int amt, int i){
//         if(amt<0 || i>=coins.size())
//             return 0;
        
//         if(amt == 0){
//             return dp[i][amt] = 1;
//         }
        
//         if(dp[i][amt] != -1)
//             return dp[i][amt];
        
//         return dp[i][amt] = solve(coins, amt-coins[i], i) + solve(coins, amt, i+1);
//     }
    
    
//     int change(int amount, vector<int>& coins) {
//         memset(dp, -1, sizeof(dp));
//         return solve(coins, amount, 0);
//     }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0)
            return 1;
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        for(int i= 0; i<=n; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i<=amount; i++){
            dp[0][i] = 0;
        }
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=amount; j++){
                if(coins[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        }
        
        return dp[n][amount];
        
    }
    
};



























