class Solution {
public:
    //Approach 2
    void backtrack(vector<int> &nums, vector<vector<int>> &ans, vector<int> temp, int s){
        ans.push_back(temp);
        
        for(int i = s; i<nums.size(); i++){
            if(i>s && nums[i] == nums[i-1])
                continue;
            temp.push_back(nums[i]);
            backtrack(nums, ans, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(nums, ans, temp, 0);
        return ans;
    }
    
    
    //Approach 1
    // void solve(vector<int> nums, int i, vector<int> curr, vector<vector<int>>& ans){
    //     if(i<0) {
    //         if(find(ans.begin(), ans.end(), curr) == ans.end())
    //             ans.push_back(curr);
    //         return ;
    //     }
    //     solve(nums, i-1, curr, ans);
    //     curr.push_back(nums[i]);
    //     solve(nums, i-1, curr, ans);
    // }
    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     int n = nums.size();
    //     vector<int> curr;
    //     sort(nums.begin(), nums.end());
    //     solve(nums, n-1, curr, ans);
    //     return ans;
    // }
};