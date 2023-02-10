class Solution {
    int dx[5] = {1,0,-1,0,1};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j])
                    q.push({i,j});
            }
        }
        if(q.size() == 0 || q.size() == n*n)
            return -1;
        
        int count = -1;
        while(!q.empty()){
            int sz = q.size();
            count++;
            while(sz--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k = 0; k<4; k++){
                    int x = i+dx[k];
                    int y = j+dx[k+1];
                    if(x>=0 && x<n && y>=0 && y<n && grid[x][y] == 0){
                        grid[x][y] = 1;
                        q.push({x,y});
                    }
                }
            }
        }
        return count;
    }
};