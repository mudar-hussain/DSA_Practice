class Solution {
public:
    void solve(vector<int> nums,int i, int target, vector<int> curr, vector<vector<int>>& ans){
        
        if(target==0) {
            if(find(ans.begin(), ans.end(), curr) == ans.end())
                ans.push_back(curr);
            return;
        }
        if(i < 0 || target < 0) return ;
        solve(nums, i-1, target, curr, ans);
        if(nums[i]<=target){
            curr.push_back(nums[i]);
            solve(nums, i, target-nums[i], curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        
        solve(candidates, n-1, target, curr, ans);
        return ans;
    }
};