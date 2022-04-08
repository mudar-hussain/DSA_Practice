class Solution {
public:
    //1st Approach (BackTracking/DP)
    bool solve(string s, vector<string>& wordDict, vector<int> &dp, int index){
        
        if(index == s.length()) return true;
        if(dp[index] != -1) return dp[index];
        
        string ss = "";
         for(int i = index; i<s.length(); i++){
             ss += s[i];
             
             if(find(wordDict.begin(), wordDict.end(), ss) != wordDict.end())
                if(solve(s, wordDict, dp, i+1)) 
                    return dp[index] = true;
             
         }
        return dp[index] = false;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n,-1);
        return solve(s,wordDict, dp, 0);
        
        
    }
};