class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dir[] = {-1,0,1,0,-1};
        
        int n = grid.size();
        int m = grid[0].size();
        
        int fresh = 0;        
        queue<pair<int, int>> q;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        int ans = -1;
        while(!q.empty()){
            ans++;
            int size = q.size();
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k = 0; k<4; k++){
                    int r = i+dir[k];
                    int c = j+dir[k+1];
                    if(r>=0 && c>=0 && r<n && c<m && grid[r][c] == 1){
                        fresh--;
                        grid[r][c] = 2;
                        q.push({r,c});
                    }
                }
            }
        }
        
        if(fresh>0) return -1;
        if(ans == -1)
            return 0;
        return ans;
        
        
        
        
    }
};



























