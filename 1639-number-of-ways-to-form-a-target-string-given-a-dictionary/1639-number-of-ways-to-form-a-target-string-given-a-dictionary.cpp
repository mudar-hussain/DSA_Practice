class Solution {
    long long MOD = 1000000007;
    int solve(string &target, vector<vector<int>> &v, vector<vector<int>> &dp, int targetIdx, int colIdx){
        if(targetIdx >= target.length()){
            return 1;
        }
        
        if((v.size()-colIdx < target.length()-targetIdx))
            return 0;
        
        if(dp[targetIdx][colIdx] != -1)
            return dp[targetIdx][colIdx];
        
        int notPickWays = solve(target, v, dp, targetIdx, colIdx+1);
        int pickWays = 0;
        if(v[colIdx][target[targetIdx] - 'a'] != 0){
            int currWays = v[colIdx][target[targetIdx] - 'a'];
            int nextWays = solve(target, v, dp, targetIdx+1, colIdx+1);
            pickWays = (currWays * (long long)nextWays)%MOD;
            
        }
        
        return dp[targetIdx][colIdx] = (pickWays + (long long)notPickWays)%MOD;
        
    }
public:
    int numWays(vector<string>& words, string target) {
        int m = words.size();
        int n = words[0].size();
        
        vector<vector<int>> v(n, vector<int>(26,0));
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                v[j][words[i][j] - 'a']++;
            }
        }
        
        vector<vector<int>> dp(target.length(), vector<int>(words[0].size(), -1));
        
        return (int)solve(target, v, dp, 0, 0);
        
        
    }
};