class Solution {
public:
    //Approach 2
    void backtrack(vector<int> &nums, vector<vector<int>> &ans, vector<int> temp, int s){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i = 0; i<nums.size(); i++){
            if(find(temp.begin(), temp.end(), nums[i]) != temp.end()) continue;
            temp.push_back(nums[i]);
            backtrack(nums, ans, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(nums, ans, temp, 0);
        return ans;
    }
    
    
    //Approach 1
//     void solve(vector<int>& nums, vector<vector<int>>& ans, int index){
//         if(index == nums.size()){
//             ans.push_back(nums);
//             return;
//         }
//         for(int i = index; i<nums.size(); i++){
//             swap(nums[i], nums[index]);
//             solve(nums, ans, index+1);
//             swap(nums[i], nums[index]);
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         // sort(nums.begin(), nums.end());
//         solve(nums, ans, 0);
//         return ans;
        
//     }
};