class Solution {
    vector<vector<int>> ans;
    void solve(int n, int k, int idx, vector<int> v){
        if(v.size() == k){
            ans.push_back(v);
            return;
        }
        if(idx>n || v.size() > k || v.size()+n-idx+1 < k)
            return;
        
        solve(n, k, idx+1, v);
        v.push_back(idx);
        solve(n, k, idx+1, v);
        
        
        
    }
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> v;
        solve(n, k, 1, v);
        
        return ans;
    }
};