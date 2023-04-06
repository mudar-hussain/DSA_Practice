class Solution {
    void dfs(vector<vector<int>>& grid,
              int i,
              int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 1){
            return;
        }
        
        grid[i][j] = 1;
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i<m; i++){
            if(grid[i][0] == 0)
                dfs(grid, i, 0);
            if(grid[i][n-1] == 0)
                dfs(grid, i, n-1);
        }
        
        for(int i = 0; i<n; i++){
            if(grid[0][i] == 0)
                dfs(grid, 0, i);
            if(grid[m-1][i] == 0)
                dfs(grid, m-1, i);
        }
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0){
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return ans;
    }
};