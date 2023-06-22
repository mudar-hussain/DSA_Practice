class Solution {
    int dp[50001][2];
    int solve(vector<int>& prices, int &fee, int canBuy, int idx){
        if(idx>=prices.size())
            return 0;
        if(dp[idx][canBuy] != -1)
            return dp[idx][canBuy];
        
        
        int profit;
        
        if(canBuy == 1){  //max(buy, skip)
            profit = max(-prices[idx]+solve(prices, fee, 0, idx+1), 
                         solve(prices, fee, 1, idx+1));
        }
        
        else{  //max(sell, skip)
            profit = max(prices[idx]-fee+solve(prices, fee, 1, idx+1), 
                         solve(prices, fee, 0, idx+1));
        }
        
        
        
        return dp[idx][canBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(prices, fee, 1, 0);
        
        return ans;
        
    }
};