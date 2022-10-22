class Solution {
public:
    int dp[301][5001];
    int solve(vector<int> &coins, int amt, int i){
        if(amt<0 || i>=coins.size())
            return 0;
        if(amt == 0){
            return dp[i][amt] = 1;
        }
        
        if(dp[i][amt] != -1)
            return dp[i][amt];
        
        return dp[i][amt] = solve(coins, amt-coins[i], i)  + solve(coins, amt, i+1);
    }
    
    
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return solve(coins, amount, 0);
    }
};