class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX, profit = 0;
        for(int i: prices){
            mini = min(mini, i);
            profit = max(profit, i-mini);
        }
        return profit;
        
        
        vector<int> gt;
        stack<int> s;
        
        for(int i = prices.size()-1; i>=0; i--){
            if(s.empty()){
                gt.push_back(prices[i]);
            }else{
                while(!s.empty() && s.top()<=prices[i])
                    s.pop();
                if(s.empty())
                    gt.push_back(prices[i]);
                else
                    gt.push_back(s.top());
            }
            s.push(prices[i]);
        }
        reverse(gt.begin(), gt.end());
        int ans = 0;
        for(int i = 0; i<prices.size(); i++){
            ans = max(ans,prices[i] - gt[i]);
        }
        return ans;
    }
};