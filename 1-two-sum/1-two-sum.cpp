class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int t = target;
        for(int i = 0; i<nums.size(); i++){
            t -= nums[i];
            auto it = find(nums.begin()+i+1,nums.end(), t);
            if(it != nums.end()){
                ans.push_back(i);
                ans.push_back(it - nums.begin());
                break;
            }
            t = target;
        }
        return ans;
    }
};