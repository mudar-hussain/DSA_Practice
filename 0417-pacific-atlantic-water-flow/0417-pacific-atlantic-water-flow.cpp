class Solution {
public:
    
    bool solve(vector<vector<int>> &heights, vector<vector<bool>> &ocean, int i, int j){
        if(i<0 || i>=heights.size() || j<0 || j>=heights[0].size() || heights[i][j] == INT_MAX)
            return false;
        
        if(ocean[i][j] == true)
            return true;
        
        int k = heights[i][j];
        heights[i][j] = INT_MAX;
        
        bool ans = false;
        
        if(i>0 && heights[i-1][j] <= k)
            ans = ans || solve(heights, ocean, i-1, j);
        
        
        if(i<heights.size()-1 && heights[i+1][j] <= k)
            ans = ans || solve(heights, ocean, i+1, j);
        
        if(j>0 && heights[i][j-1] <= k)
            ans = ans || solve(heights, ocean, i, j-1);
        
        if(j<heights[0].size()-1 && heights[i][j+1] <= k)
            ans = ans || solve(heights, ocean, i, j+1);
        
        
        ocean[i][j] = ans;
        heights[i][j] = k;
        return ans;
        
        
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> p(m, vector<bool>(n, false));
        vector<vector<bool>> a(m, vector<bool>(n, false));
        for(int i = 0; i<m; i++){
            p[i][0] = 1; 
            a[i][n-1] = 1;
        }
        for(int i = 0; i<n; i++){
            a[m-1][i] = 1;
            p[0][i] = 1;
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(solve(heights, p, i, j) && solve(heights, a, i, j))
                    ans.push_back({i, j});
            }
        }
        
        
        
        return ans;
    }
};