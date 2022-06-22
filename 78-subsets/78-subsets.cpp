class Solution {
    private:
    
public:
    //Approach 2
    void backtrack(vector<int> &nums, vector<vector<int>> &ans, vector<int> temp, int s){
        ans.push_back(temp);
        
        for(int i = s; i<nums.size(); i++){
            temp.push_back(nums[i]);
            backtrack(nums, ans, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(nums, ans, temp, 0);
        return ans;
    }
    
    
    //Approach 1
    // void solve(vector<int> in, vector<int> op){
    //     if(in.size()==0){
    //         ans.push_back(op);
    //         return;
    //     }
    //     vector<int> op1 = op;
    //     vector<int> op2 = op;
    //     op2.push_back(in[0]);
    //     in.erase(in.begin()+0);
    //     solve(in,op1);
    //     solve(in,op2);
    //     return;
    // }
    // vector<vector<int>> subsets(vector<int>& nums) {  
    //     vector<int> op;
    //     solve(nums,op);
    //     return ans;
    // }
};

    











