class Solution {
public:
    int dp[102];
    
    int solve(const string &s, int idx){
        if(idx == s.length())
            return 1;
        if(dp[idx] != -1)
            return dp[idx];
        string temp = "";
        int ans = 0;
        for(int i = idx; i<s.length() && i<idx+2; i++){
            temp.push_back(s[i]);
            if(temp == "0"){
                break;
            }
            if(stoi(temp) <= 26){
                ans += solve(s, i+1);
            }
        }
        
        return dp[idx] = ans;
    }
    
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0);
        
    }
};