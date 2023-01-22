class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    
    void dfs(string &s, vector<string> v, int idx){
        if(idx >= s.length()){
            ans.push_back(v);
            return;
        }
        
        for(int i = idx; i<s.length(); i++){
            if(isPalindrome(s, idx, i)){
                v.push_back(s.substr(idx, i - idx + 1));
                dfs(s, v, i+1);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> v;
        dfs(s, v, 0);
        return ans;
    }
};