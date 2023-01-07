class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> highest(n, vector<int>(n,INT_MAX));
        for(int i = 0; i<n; i++){
            int hmaxi = -1;
            int vmaxi = -1;
            for(int j = 0; j<n; j++){
                hmaxi = max(hmaxi, grid[i][j]);
                vmaxi = max(vmaxi, grid[j][i]);
            }
            for(int j = 0; j<n; j++){
                highest[i][j] = min(highest[i][j], hmaxi);
                highest[j][i] = min(highest[j][i], vmaxi);
            }
        }
        
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                count += highest[i][j] - grid[i][j];
            }
        }
        
        return count;
        
        
        
        
    }
};