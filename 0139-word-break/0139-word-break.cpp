class Solution {
public:
    int n;
    int dp[301];
    
    bool dfs(string &s, vector<string>& wordDict, int idx){
        if(idx >= n)
            return true;
        if(dp[idx] != -1)
            return dp[idx];
        
        bool ans = false;
        string newWord = "";
        for(auto word: wordDict){
            int sz = word.size();
            if(sz > n-idx)
                continue;
            newWord = s.substr(idx, sz);
            if(newWord == word)
                ans |= dfs(s, wordDict, idx+sz);
            
            dp[idx] = ans;
            if(ans)
                return ans;
        }
        return dp[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
        return dfs(s, wordDict, 0);
    }
};