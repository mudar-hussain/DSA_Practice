class Solution {
public:
    int n,m;
    int x,y;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0|| i>=n || j>=m || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        for(int k = 0; k<4; k++){
            x = i+dx[k];
            y = j+dy[k];
            dfs(grid, x,y);
        }
    }
        
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};