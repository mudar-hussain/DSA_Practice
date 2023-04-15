class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        
        vector<vector<int>> pref(n+1, vector<int>());
        
        for(int i = 0; i<n; i++){
            pref[i].resize(piles[i].size());
            pref[i][0] = piles[i][0];
            for(int j = 1; j<piles[i].size(); j++){
                pref[i][j] = piles[i][j] + pref[i][j-1];
            }
        }
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=k; j++){
                for(int cur = 0; cur<=pref[i-1].size(); cur++){
                    if(cur<=j){
                        if(cur>0){
                            dp[i][j] = max(dp[i][j], dp[i-1][j-cur] + pref[i-1][cur-1]);
                        }else
                            dp[i][j] = max(dp[i][j], dp[i-1][j-cur]);
                            
                    }
                }
            }
        }
        
        return dp[n][k];
    }
};