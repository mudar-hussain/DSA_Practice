class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int s = 0;
        for(int i: nums){
            s+=i;
            ans.push_back(s);
        }
        return ans;
            
    }
};