class Solution {
    int dp[31];
public:
    int solve(int n){
        if(n == 0 || n == 1)
            return n;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = solve(n-1)+solve(n-2);
    }
    int fib(int n) {
        if(n == 0 || n == 1)
            return n;
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};