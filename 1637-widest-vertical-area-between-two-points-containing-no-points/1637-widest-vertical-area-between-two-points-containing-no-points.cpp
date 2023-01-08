class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> s;
        for(auto i: points){
            s.insert(i[0]);
        }
        
        int maxDistance = INT_MIN;
        int prev = 0;
        for(auto i: s){
            if(maxDistance == INT_MIN){
                maxDistance = 0;
            }else
            maxDistance = max(maxDistance, i-prev);
            prev = i;
        }
        return maxDistance;
    }
};