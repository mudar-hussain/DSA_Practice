class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        unordered_set<int> s;
        for(auto i: points){
            s.insert(i[0]);
        }
        vector<int> v;
        for(int i: s){
            v.push_back(i);
        }
        if(v.size() == 1)
            return 0;
        
        sort(v.begin(), v.end());
        int maxDistance = INT_MIN;
        for(int i = 1; i<v.size(); i++){
            maxDistance = max(maxDistance, v[i]-v[i-1]);
        }
        return maxDistance;
    }
};