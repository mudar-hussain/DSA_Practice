class Solution {
public:
    //1st Approach (BackTracking)
    bool solve(string s, vector<string>& wordDict, vector<int> &dp, int index, vector<string>& ans, string &str){
        
        if(index == s.length()){
            str.pop_back();
            ans.push_back(str);
            return true;
        } 
        
        // if(dp[index] != -1) return dp[index];
        string temp;
        string ss = "";
         for(int i = index; i<s.length(); i++){
             ss += s[i];
             
             if(find(wordDict.begin(), wordDict.end(), ss) != wordDict.end()){
                 temp = str;
                 str += ss + " ";
                 if(solve(s, wordDict, dp, i+1, ans, str)) 
                    dp[index] = true;
                 str = temp;
             }
                
             
         }
        return dp[index] = false;
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n,-1);
        vector<string> ans;
        string str = "";
        solve(s,wordDict, dp, 0, ans, str);
        return ans;
    }
};