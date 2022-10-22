class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> um;
        for(int i: nums){
            if(um[i] == 0)
                um[i]++;
            else ans.push_back(i);
        }
        return ans;
    }
};