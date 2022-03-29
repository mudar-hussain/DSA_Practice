class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> um;
        vector<int> ans;
        for(int num: nums){
            um[num]++;
        }
        for(auto x: um){
            if(x.second>n/3){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};