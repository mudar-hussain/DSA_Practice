class Solution {
    private:
    
public:
    //Approach 2
//     void backtrack(vector<int> &nums, vector<vector<int>> &ans, vector<int> temp, int s){
//         ans.push_back(temp);
        
//         for(int i = s; i<nums.size(); i++){
//             temp.push_back(nums[i]);
//             backtrack(nums, ans, temp, i+1);
//             temp.pop_back();
//         }
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> temp;
//         backtrack(nums, ans, temp, 0);
//         return ans;
//     }
    
    
    //Approach 1
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> op, int s){
        if(s == nums.size()){
            ans.push_back(op);
            return;
        }
        
        solve(nums, ans, op, s+1);
        op.push_back(nums[s]);
        solve(nums, ans, op, s+1);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {  
        vector<vector<int>> ans;
        vector<int> op;
        solve(nums, ans, op, 0);
        return ans;
    }
};

    











