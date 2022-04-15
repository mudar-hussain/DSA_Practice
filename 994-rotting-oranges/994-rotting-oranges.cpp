class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        
        for(int i= 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        int ans = 0;
        q.push({-1,-1});
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            if(i == -1 && j == -1 && q.size() == 1){
                q.pop();
                break;
            }else if(i == -1 && j == -1 && q.size() > 1){
                ans++;
                q.pop();
                q.push({-1,-1});
            }else{
                if(i-1>=0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    q.push({i-1,j});
                }
                if(j-1>=0 && grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    q.push({i,j-1});
                }
                if(i+1<m && grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    q.push({i+1,j});
                }
                if(j+1<n && grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    q.push({i,j+1});
                }
                q.pop();
            }
        }
        for(int i= 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return ans;
        
    }
};



































