class Solution {
public:
    vector<vector<int>> ans;
    void solve(int k, int target, int ind, vector<int> temp){
        
        if(target == 0 && k == 0){
            ans.push_back(temp);
            return;
        }
        if(target == 0 || k == 0)
            return;
        for(int i = ind; i<=9; i++){
            if(i>target)
                break;
            
            temp.push_back(i);
            solve(k-1, target-i, i+1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        solve(k, n, 1, temp);
        return ans;
    }
};