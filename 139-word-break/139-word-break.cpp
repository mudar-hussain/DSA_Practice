class Solution {
public:
    
    bool solve(string s, vector<string>& wordDict, vector<int> &dp, int index){
        
        if(index == s.length()) return true;
        if(dp[index] != -1) return dp[index];
        
         for(int i = index; i<s.length(); i++){
             string ss = s.substr(index, i-index+1);
             
             for(auto wd: wordDict){
                if(wd == ss){
                    if(solve(s, wordDict, dp, i+1)) 
                        return dp[index] = true;
                    else 
                        break;
                }
             }
             
         }
        return dp[index] = false;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n,-1);
        return solve(s,wordDict, dp, 0);
        
        
    }
};