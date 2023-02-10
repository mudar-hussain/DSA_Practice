class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> ones;
        vector<pair<int, int>> zeros;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j])
                    ones.push_back({i,j});
                else
                    zeros.push_back({i,j});
            }
        }
        if(ones.size() == 0 || zeros.size() == 0)
            return -1;
        int ans = INT_MIN;
        for(auto z: zeros){
            int cur = INT_MAX;
            for(auto o: ones)
                cur = min(cur, (abs(z.first-o.first)+abs(z.second-o.second)));
            ans = max(ans, cur);
        }
        
        return ans==INT_MAX? -1: ans;
        
    }
};