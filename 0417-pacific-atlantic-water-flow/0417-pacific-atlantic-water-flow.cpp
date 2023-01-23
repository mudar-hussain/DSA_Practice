class Solution {
public:
    int n, m;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    void solve(vector<vector<int>> &heights,vector<vector<int>> &ocean, int i, int j, int prev){
        if(i<0 || j<0 || i>=n || j>=m || ocean[i][j] == 1 || heights[i][j] < prev)
            return;
        
        ocean[i][j] = 1;
        int x, y;
        for(int k = 0; k<4; k++){
            x = i+dx[k];
            y = j+dy[k];
            solve(heights, ocean, x, y, heights[i][j]);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>> ans;
        
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        
        
        for(int i = 0; i<n; i++){
            solve(heights, pacific, i, 0, INT_MIN);
            solve(heights, atlantic, i, m-1, INT_MIN);  
        }
        
        for(int j = 0; j<m; j++){
            solve(heights, pacific, 0, j, INT_MIN);
            solve(heights, atlantic, n-1, j, INT_MIN);       
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1)
                    ans.push_back({i,j});
            }
        }
        return ans;
        
    }
};