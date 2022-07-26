class Solution {
    int dp[38];
public:
    int solve(int n){
        if(n <= 1) return n;
        if(n == 2) return 1;
        if(dp[n] != -1) 
            return dp[n];
        return dp[n] = solve(n-1)+solve(n-2)+solve(n-3);
    }
    int tribonacci(int n) {
        if(n <= 1) return n;
        if(n == 2) return 1;
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};