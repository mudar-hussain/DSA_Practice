class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans;
        bool present;
        for(int i = 0; i<n; i++){
            present = false;
            for(int j = i+1; j<n; j++){
                if(prices[i]>=prices[j]){
                    ans.push_back(prices[i]-prices[j]);
                    present = true;
                    break;
                }
            }
            if(present == false) ans.push_back(prices[i]);
        }
        return ans;
    }
};