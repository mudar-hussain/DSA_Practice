class Solution {
public:
    void dp(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || vis[i][j] == true || grid[i][j] == '0')
            return;
        vis[i][j] = true;
        dp(grid, vis, i-1, j);
        dp(grid, vis, i, j-1);
        dp(grid, vis, i+1, j);
        dp(grid, vis, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1' && vis[i][j] == false){
                    ans++;
                    dp(grid, vis, i, j);
                }
                    
            }
        }
        return ans;
    }
};