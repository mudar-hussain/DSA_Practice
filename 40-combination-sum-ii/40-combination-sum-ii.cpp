class Solution {
public:
    //2nd Approach
    
    void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector < vector < int >> ans;
        vector < int > ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
    //1st Approach
//     void solve(vector<int> nums,int i, int target, vector<int> curr, vector<vector<int>>& ans){
        
//         if(target==0) {
//             if(find(ans.begin(), ans.end(), curr) == ans.end())
//                 ans.push_back(curr);
//             return;
//         }
//         if(i < 0 || target < 0) return ;
//         solve(nums, i-1, target, curr, ans);
//         if(nums[i]<=target){
//             curr.push_back(nums[i]);
//             solve(nums, i-1, target-nums[i], curr, ans);
//             curr.pop_back();
//         }
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         vector<vector<int>> ans;
//         vector<int> curr;
//         sort(candidates.begin(), candidates.end());
//         int n = candidates.size();
        
//         solve(candidates, n-1, target, curr, ans);
//         return ans;
//     }
};