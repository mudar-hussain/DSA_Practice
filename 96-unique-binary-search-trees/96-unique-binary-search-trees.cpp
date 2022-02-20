class Solution {
public:
    // int numTrees(int n) {
    //     if(n==0 || n==1) return 1;
    //     int count = 0;
    //     for(int i = 1; i<=n; i++){
    //         count += numTrees(i-1) * numTrees(n-i);
    //     }
    //     return count;
    // }
    int dp[20] = {0};
    int numTrees(int n) {
        if(n==0 || n==1) return 1;
        if(dp[n] != 0) return dp[n];
        int count = 0;
        for(int i = 1; i<=n; i++){
            count += numTrees(i-1) * numTrees(n-i);
        }
         dp[n] = count;
        return count;
    }
};