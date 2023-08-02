class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int index){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i<nums.size(); i++){
            swap(nums[i], nums[index]);
            solve(nums, ans, index+1);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        // sort(nums.begin(), nums.end());
        solve(nums, ans, 0);
        return ans;
        
    }
};