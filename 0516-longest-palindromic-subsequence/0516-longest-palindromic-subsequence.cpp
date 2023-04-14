class Solution {
    int solve(string s, vector<vector<int>> &dp, int start, int end){
        if(start == end)
            return 1;
        if(start>end)
            return 0;
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        if(s[start] == s[end])
            return dp[start][end] = 2 + solve(s, dp, start+1, end-1);
        int leftLeave = solve(s, dp, start+1, end);
        int rightLeave = solve(s, dp, start, end-1);
        
        return dp[start][end] = max(leftLeave, rightLeave);
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // int ans = solve(s, dp, 0, s.length()-1);
        // return ans;
        vector<vector<int>>dp(n, vector<int>(n, 0));
        //for n length string we need LPS for string with length (n - 1) or (n - 2)
        //We need to already have LPS for smaller lengths before moving to greater lengths
        //so we need to go bottom up 
        //Calculating LPS for all strings of length = 1 to length = n
        //================================================================================
        for (int len = 1; len <= n; len++)
        {
            for (int start = 0; start <= (n - len); start++)
            {
                int end = start + len - 1; //[start, end] denotes the string under consideration
                if (len == 1) { dp[start][end] = 1; continue; }
                
                if (s[start] == s[end]) dp[start][end] = 2 + dp[start + 1][end - 1];
                else dp[start][end] = max(dp[start + 1][end], dp[start][end - 1]); 
            }
        }
        //=====================================================================================
        return dp[0][n - 1];
    }
};