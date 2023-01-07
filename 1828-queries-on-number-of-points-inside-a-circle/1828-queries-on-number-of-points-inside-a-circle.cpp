class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        int n= queries.size();
        int m = points.size();
        int r,x1,x2,y1,y2, count;
        for(int i = 0; i<n; i++){
            x1 = queries[i][0];
            y1 = queries[i][1];
            r = queries[i][2] * queries[i][2];
            count = 0;
            for(int j = 0; j<m; j++){
                x2 = points[j][0];
                y2 = points[j][1];
                if(r >= ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)))
                    count++;
            }
            ans.push_back(count);
        }
        
        return ans;
    }
};