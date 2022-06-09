class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    
    void MCM(string &s, vector<vector<string>> &ans, vector<string> &ds, int i, int n){
        if(i==n){
            ans.push_back(ds);
            return;
        }
        
        for(int k = i; k<n; k++){
            if(isPalindrome(s, i, k)){
                ds.push_back(s.substr(i, k-i+1));
                MCM(s, ans, ds, k+1, n);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        MCM(s, ans, ds, 0, s.length());
        return ans;
    }
};