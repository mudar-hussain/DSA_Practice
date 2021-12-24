class Solution {
    private:
    vector<vector<int>> ans;
    
public:
    void solve(vector<int> in, vector<int> op){
        if(in.size()==0){
            ans.push_back(op);
            return;
        }
        vector<int> op1 = op;
        vector<int> op2 = op;
        op2.push_back(in[0]);
        in.erase(in.begin()+0);
        solve(in,op1);
        solve(in,op2);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {  
        vector<int> op;
        solve(nums,op);
        return ans;
    }
};

    











