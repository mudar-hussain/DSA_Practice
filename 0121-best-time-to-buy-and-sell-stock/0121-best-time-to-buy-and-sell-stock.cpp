class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int profit = 0;
        for(int i: prices){
            mini = min(mini, i);
            profit = max(profit, i-mini);
        }
        
        return profit;
    }
};