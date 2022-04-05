class Solution {
public:
    void solve(vector<int> nums, int i, vector<int> curr, vector<vector<int>>& ans){
        if(i<0) {
            if(find(ans.begin(), ans.end(), curr) == ans.end())
                ans.push_back(curr);
            return ;
        }
        solve(nums, i-1, curr, ans);
        curr.push_back(nums[i]);
        solve(nums, i-1, curr, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> curr;
        sort(nums.begin(), nums.end());
        solve(nums, n-1, curr, ans);
        return ans;
    }
};