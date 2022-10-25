class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, int target, vector<int> temp, int idx){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i = idx; i<nums.size(); i++){
            if(nums[i]>target)
                break;
            temp.push_back(nums[i]);
            solve(nums, ans, target-nums[i], temp, i);
            temp.pop_back();
        }
            
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, ans, target, temp, 0);
        return ans;
    }
};