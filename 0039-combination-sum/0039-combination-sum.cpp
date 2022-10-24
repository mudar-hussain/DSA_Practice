class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, int target, vector<int> temp, int idx){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(idx>=nums.size())
            return;
        
        solve(nums, ans, target, temp, idx+1);
        if(nums[idx]<=target){
            temp.push_back(nums[idx]);
            solve(nums, ans, target-nums[idx], temp, idx);
        }
            
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, ans, target, temp, 0);
        return ans;
    }
};