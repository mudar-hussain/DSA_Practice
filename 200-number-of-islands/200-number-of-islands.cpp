class Solution {
public:
    void dp(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size()  || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dp(grid, i-1, j);
        dp(grid, i, j-1);
        dp(grid, i+1, j);
        dp(grid, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dp(grid, i, j);
                }
                    
            }
        }
        return ans;
    }
};