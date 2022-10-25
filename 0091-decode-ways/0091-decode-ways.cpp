class Solution {
public:
    int dp[101];
    int solve(string &s, string temp, int idx){
        if(idx >= s.length())
            return 1;
        if(s[idx] == '0')
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        
        
        temp += s[idx];
        int a = solve(s, temp, idx+1);
        int b = 0;
        if(idx < s.length()-1){
            if(s[idx] == '1' || (s[idx] == '2' && s[idx+1] < '7'))
                b = solve(s, temp+s[idx+1], idx+2);
        }
        return dp[idx] = a+b;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        string temp = "";
        return solve(s, temp, 0);
    }
};