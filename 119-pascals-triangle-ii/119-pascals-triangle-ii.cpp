class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        
        if(rowIndex==0)return ans;
        
        unsigned long long base = rowIndex;
        ans.push_back(rowIndex);
        
        for(int i = 1; i<rowIndex; i++){
            unsigned long long z  = (ans[i]*(base-i))/(i+1);
            ans.push_back(z);
        }
        return ans;
    }
};