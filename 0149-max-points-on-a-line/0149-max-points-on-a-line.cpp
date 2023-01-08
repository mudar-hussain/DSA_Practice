class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2)
            return n;
        int maxCount = 0;
        for(int i = 0; i<n; i++){
            unordered_map<double, int> um;
            for(int j = i+1; j<n; j++){
                //perpendicular case
                if(points[i][0] == points[j][0])
                    um[90]++;
                
                double slope = (double)(points[i][1] - points[j][1])/(double)(points[i][0] - points[j][0]);
                um[slope]++;
            }
            for(auto i: um){
                maxCount = max(maxCount, i.second+1);
            }
        }
        return maxCount;
    }
};