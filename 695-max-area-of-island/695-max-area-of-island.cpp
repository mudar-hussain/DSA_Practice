class Solution {
public:
    int area(vector<vector<int>>& image, int i, int j){
        int m = image.size();
        int n = image[0].size();
        int ans = 0;
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int, int>> q;
        q.push({i, j});
        image[i][j] = 2;
        while(!q.empty()){
            ans++;
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++){
                int nx = x+dir[i][0];
                int ny = y+dir[i][1];
                if(nx>=0 && ny>=0 && nx<m && ny<n && image[nx][ny] == 1){
                    image[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    int temp = area(grid, i, j);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};












