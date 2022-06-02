class Solution {
public:
    //2nd Approach
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
    
    
    //1st Approach
//     int solve(string a, string b, int n, int m, vector<vector<int>> &dp){
//         if(n == -1 || m == -1){
//             return 0;
//         }
        
//         if(dp[n][m] != -1){
//             return dp[n][m];
//         }
        
//         if(a[n] == b[m])
//             return dp[n][m] = 1 + solve(a, b, n-1, m-1, dp);
//         else{
//             return dp[n][m] = max(solve(a, b, n-1, m, dp), solve(a, b, n, m-1, dp));
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size();
//         int m = text2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
//         return solve(text1, text2, n-1, m-1, dp);
//     }
};