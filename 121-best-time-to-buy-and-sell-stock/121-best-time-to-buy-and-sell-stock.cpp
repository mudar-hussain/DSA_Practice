class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int min_p = INT_MAX, profit = 0;
        for(int i:prices){
            if(i<min_p) min_p = i;
            else if(i>min_p){
                profit = max(profit, i-min_p);
            }
        }
        return profit;
    }
};