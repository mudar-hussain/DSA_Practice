class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int profit = 0;
        for(int i: prices){
            minPrice = min(minPrice, i);
            profit = max(profit, i-minPrice);
        }
        return profit;
    }
};