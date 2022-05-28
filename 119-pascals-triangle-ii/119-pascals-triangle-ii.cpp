class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long k = 1;
        for(int i = 0; i<=rowIndex; i++){
            ans.push_back(k);
            k  = k* (rowIndex-i) / (i+1);
            
        }
        return ans;
    }
};