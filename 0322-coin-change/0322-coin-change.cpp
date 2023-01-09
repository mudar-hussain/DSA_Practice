class Solution {
public:
    int dp[13][10001];
    int solve(vector<int> &coins, int amount, int i){
        if(i==coins.size()-1){
            if(amount % coins[i] == 0)
                return amount/coins[i];
            else
                return 1e9;
        }
        
        
        if(dp[i][amount] != -1)
            return dp[i][amount];
        
        int notPick = solve(coins, amount, i+1);
        int pick = coins[i]<=amount? 1+solve(coins, amount-coins[i], i): 1e9;
        
        return dp[i][amount] = min(pick, notPick);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(coins, amount, 0);
        
        return ans == 1e9 ? -1:ans;
    }
};