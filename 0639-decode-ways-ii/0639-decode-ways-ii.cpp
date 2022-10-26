class Solution {
public:
    int mod = 1e9 + 7;
    long long dp[100001];
    long long solve(string &s, int idx){
        if(idx == s.length())
            return 1;
        if(s[idx] == '0')
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        long long first = 0, second = 0, third = 0;
        
        if(s[idx] == '*')
            first = (9*solve(s, idx+1)%mod)%mod;
        else
            first = solve(s, idx+1)%mod;
        
        if(idx < s.size()-1){
            if(s[idx] == '1' || s[idx] == '*'){
                
                if(s[idx+1] == '*')
                    second = (9*solve(s, idx+2)%mod)%mod;
                else
                    second = solve(s, idx+2)%mod;
            }
            
            if(s[idx] == '2' || s[idx] == '*'){
                
                if(s[idx+1] == '*')
                    third = (6*solve(s, idx+2)%mod)%mod;
                else if(s[idx+1] < '7')
                    third = solve(s, idx+2)%mod;
            }
        }
        
        
        return dp[idx] = (((first+second)%mod)+third)%mod;
    }
    
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        
        return (solve(s, 0))%mod;
    }
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
};