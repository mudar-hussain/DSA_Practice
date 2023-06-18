class Solution {
    int mod = 1000000007;
    int dir[5] = {-1,0,1,0,-1};
    int dp[1001][1001];
    
    bool isValid(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>= grid.size() || j<0 || j>=grid[0].size())
            return false;
        
        return true;
    }
    
    
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 1;
        
        for(int k = 0; k<4; k++){
            int x = i+dir[k];
            int y = j+dir[k+1];
            
            if(isValid(grid, x, y) && grid[x][y] > grid[i][j]){
                ans = (ans%mod + dfs(grid, x, y)%mod)%mod;
            }
        }
        
        return dp[i][j] = ans;
    }
    
public:
    int countPaths(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        long long ans = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                ans = (ans%mod + dfs(grid, i, j)%mod)%mod;
            }
        }
        
        return ans;
    }
};