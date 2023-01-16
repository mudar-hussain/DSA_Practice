class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, 0);
        vector<int> prev(amount+1, 0);
        
        for(int i = 0; i<=amount; i++){
            prev[i] = i%coins[0] == 0? i/coins[0]:1e9;
        }
        
        for(int i = 1;i<n; i++) {
            for(int j = 0; j<=amount; j++){
                int pick = 0 + prev[j];
                int notPick = j>=coins[i]? 1 + dp[j-coins[i]] : 1e9;
                
                dp[j] = min(pick, notPick);
            }
            prev = dp;
        }
        return prev[amount] == 1e9? -1: prev[amount];
    }
};