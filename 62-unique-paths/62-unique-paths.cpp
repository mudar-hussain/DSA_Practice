class Solution {
public:
    //1st Approach
    int uniquePaths(int m, int n) {
        if(n == 1 || m == 1) return 1;
        double ans = 1;
        int N = m+n-2;
        int r = m-1;
        for(int i = 1; i<=r; i++){
            ans = ans * (N-r+i) / i;
        }
        
        return (int)ans;
    }
    
    
    //2nd Approach
//     int solve(int i, int j, int m, int n, vector<vector<int>> dp){
//         if(i==(n-1) && j==(m-1)) return 1;
//         if(i>=n || j>=m) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         dp[i][j] = solve(i+1,j,m,n,dp)+solve(i,j+1,m,n,dp);
//         return dp[i][j];
//     }
//     int uniquePaths(int m, int n) {
//         if(n == 1 || m == 1) return 1;
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
//         return solve(0, 0, m, n, dp);
//     }
    
    //3rd Approach
//     int uniquePaths(int m, int n) {
//         if(n == 1 || m == 1) return 1;
        
//         return uniquePaths(m-1, n)+uniquePaths(m, n-1);
//     }
};